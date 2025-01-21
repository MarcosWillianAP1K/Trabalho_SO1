#include "../Outros/Cronometro.h"
#include "../Outros/Escrever_resultado.h"
#include "Soma_threads_1.h"

#define NUM_DE_THREAD 2






void *soma_2_thread_pecorrer_arquivo(void *arg)
{
    char *nome_arquivo = (char *)arg;
    FILE *arquivo = fopen(nome_arquivo, "r");
    int soma = 0;
    int numero = 0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    clock_t cronometro = cronometro_iniciar();

    while (fscanf(arquivo, "%d\n", &numero) != EOF)
    {
        soma += numero;
    }

    cronometro = cronometro_finalizar(cronometro);

    double *tempo_ptr = malloc(sizeof(double));
    *tempo_ptr = 0;
    
    *tempo_ptr = converter_para_segundos(cronometro);

    fclose(arquivo);

    return tempo_ptr;
}



void soma_thread_1_abrir_arquivo(int num_de_arq, int num_de_numb)
{
    FILE *arquivo;
    char resultado[100];
    double tempo_total = 0;

    #define DIRETORIO_RESULTADO "Resultados/Result_soma_2_thread.txt"
    

    criar_resetar_arquivo(DIRETORIO_RESULTADO);

    sprintf(resultado, "Soma 2 thread:\n\nCom %d arquivos.\nCada arquivo com %d numeros\n\n", num_de_arq, num_de_numb);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

    for (int i = 0; i < num_de_arq; i+=NUM_DE_THREAD)
    {
        pthread_t thread[NUM_DE_THREAD];

        char nome_arquivo1[100];

        
        for (int j = 0; j < NUM_DE_THREAD && j+i < num_de_arq; j++)
        {
            sprintf(nome_arquivo1, "Codigo/Arquivos_de_teste/testes/teste_%d.txt", i+j+1);

            pthread_create(&thread[j], NULL, soma_2_thread_pecorrer_arquivo, (void *)nome_arquivo1);
        }

        for (int j = 0; j < NUM_DE_THREAD && j+i < num_de_arq; j++)
        {
            double *tempo_ptr;
            pthread_join(thread[j], (void **)&tempo_ptr);

            tempo_total += *tempo_ptr;

            sprintf(resultado, "Tempo de duracao do arquivo %d: %f\n", i+j+1, *tempo_ptr);
            escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

            free(tempo_ptr);
        }

    }

    sprintf(resultado, "\nTempo total de duracao: %f\n", tempo_total);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);
}