
#include "Organizacao_threads_1.h"
#include "../Outros/Cronometro.h"
#include "../Outros/Escrever_resultado.h"
#include "../Outros/Algos_de_ordernacao.h"
#include <string.h>

#define NUM_DE_THREAD 2

//Variaveis globais para os threads acessarem
int NUM_DE_ARQUIVOS = 0;
int NUM_DE_NUMEROS = 0;


typedef struct RESULTADO_THREAD
{
    double tempo;
    char *resultado;
} RESULTADO_THREAD;



void *Organizacao_2_thread_pecorrer_arquivo(void *nome_arquivo)
{
    FILE *arquivo;
    char *resultado = (char *)malloc(sizeof(char) * 150);
    int *vetor = (int *)malloc(NUM_DE_NUMEROS * sizeof(int));
    double tempo_total = 0;

    arquivo = fopen((char *)nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", (char *)nome_arquivo);
        exit(1);
    }


    clock_t cronometro = cronometro_iniciar();

    Preencher_vetor_arquivo(arquivo, NUM_DE_NUMEROS, vetor);
    
    cronometro = cronometro_finalizar(cronometro);

    double tempo = converter_para_segundos(cronometro);
    RESULTADO_THREAD *resultado_thread = (RESULTADO_THREAD *)malloc(sizeof(RESULTADO_THREAD));
    resultado_thread->tempo = tempo;

    sprintf(resultado, "Tempo de preencher: %f   ", tempo);
    

    cronometro = cronometro_iniciar();
    quick_sort(vetor, NUM_DE_NUMEROS);
    cronometro = cronometro_finalizar(cronometro);

    tempo = converter_para_segundos(cronometro);

    resultado_thread->tempo += tempo;

    free(vetor);
    fclose(arquivo);

    sprintf(resultado + strlen(resultado), "Tempo de organizacao: %f\n", tempo);
    resultado_thread->resultado = resultado;

    return resultado_thread;
}


void Organizacao_thread_1_abrir_arquivo(int num_de_arq, int num_de_numb)
{
    NUM_DE_ARQUIVOS = num_de_arq;
    NUM_DE_NUMEROS = num_de_numb;
    
    FILE *arquivo;
    double tempo_total = 0;

    #define DIRETORIO_RESULTADO "Resultados/Result_organizacao_thread_1.txt"

    criar_resetar_arquivo(DIRETORIO_RESULTADO);

    char resultado[100];

    sprintf(resultado, "Organizacao 2 thread:\n\nCom %d arquivos.\nCada arquivo com %d numeros\n\n", num_de_arq, num_de_numb);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);


    for (int i = 0; i < num_de_arq; i+=NUM_DE_THREAD)
    {
        pthread_t thread[NUM_DE_THREAD];

        char nome_arquivo1[100];

        
        for (int j = 0; j < NUM_DE_THREAD && j+i < num_de_arq; j++)
        {
            sprintf(nome_arquivo1, "Codigo/Arquivos_de_teste/testes/teste_%d.txt", i+j+1);

            pthread_create(&thread[j], NULL, Organizacao_2_thread_pecorrer_arquivo, (void *)nome_arquivo1);
        }

        for (int j = 0; j < NUM_DE_THREAD && j+i < num_de_arq; j++)
        {
            RESULTADO_THREAD *result;
            pthread_join(thread[j], (void **)&result);

            sprintf(nome_arquivo1, "teste_%d.txt: ", i+j+1);
            escrever_resultado_anexar(DIRETORIO_RESULTADO, nome_arquivo1);

            tempo_total += result->tempo;

            escrever_resultado_anexar(DIRETORIO_RESULTADO, result->resultado);
            
            free(result->resultado);
            free(result);
        }
    }

    sprintf(resultado, "\nTempo total de organizacao: %f\n", tempo_total);

    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

}