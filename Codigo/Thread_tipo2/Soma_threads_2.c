#include "Soma_threads_2.h"
#include "../Outros/Cronometro.h"
#include "../Outros/Escrever_resultado.h"


typedef struct Inicio_fim
{
    int inicio;
    int fim;
    int num_do_thread;
} Inicio_fim;




void *soma_thread(void *arg) 
{
    Inicio_fim *p = (Inicio_fim *) arg;

    FILE *arquivo;
    double *tempo_total = malloc(sizeof(double));
    char resultado[100];
    char arq_aux[50];

    sprintf(arq_aux, "Codigo/Thread_tipo2/aux%d.txt", p->num_do_thread);

    criar_resetar_arquivo(arq_aux);

    sprintf(resultado, "Thread %d:\n\n", p->num_do_thread);

    escrever_resultado_anexar(arq_aux, resultado);


    for (int i = p->inicio; i < p->fim; i++)
    {
        char nome_arquivo[100];
        
        sprintf(nome_arquivo, "Codigo/Arquivos_de_teste/testes/teste_%d.txt", i);
        arquivo = fopen(nome_arquivo, "r");

        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
            exit(1);
        }

        clock_t cronometro = cronometro_iniciar();

        int soma = soma_simples_pecorrer_arquivo(arquivo);

        cronometro = cronometro_finalizar(cronometro);

        double tempo = converter_para_segundos(cronometro);

        *tempo_total += tempo;

        sprintf(nome_arquivo, "teste_%d.txt", i);

        sprintf(resultado, "%s: Tempo de duracao: %f\n", nome_arquivo, tempo);
        
        escrever_resultado_anexar(arq_aux ,resultado);

        // printf("Soma do arquivo %s: %d\n", nome_arquivo, soma);

        fclose(arquivo);
    }

    

    sprintf(resultado, "Resultado do thread %d:  Tempo total: %f\n\n", p->num_do_thread,*tempo_total);
    escrever_resultado_anexar(arq_aux, resultado);

    return tempo_total;
}





void soma_threads_tipo2_abrir_arquivo(int num_de_arq, int num_de_numb, int num_de_thread) 
{

    if (num_de_thread < 1 || num_de_thread > 10 || num_de_arq < 1 || num_de_numb < 1 ) 
    {
        printf("Numero de threads invalido\n");
        exit(1);
    }
    
    pthread_t thread[num_de_thread];
    double tempo_total = 0;
    char resultado[100];
    #define DIRETORIO_RESULTADO "Resultados/Result_soma_multi_thread.txt"
    
    criar_resetar_arquivo(DIRETORIO_RESULTADO);

    sprintf(resultado, "Soma multi thread:\n\nCom %d arquivos.\nCada arquivo com %d numeros\n\n", num_de_arq, num_de_numb);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);
    int divisao = num_de_arq / num_de_thread;
    Inicio_fim *p[num_de_thread];

    for (int i = 0; i < num_de_thread ; i++)
    {
        p[i] = malloc(sizeof(Inicio_fim));

        p[i]->inicio = (i * divisao) + 1;
        p[i]->fim = (i + 1) * divisao;
        p[i]->num_do_thread = i + 1;

        pthread_create(&thread[i], NULL, soma_thread, (void *)&p);
    }


    for (int i = 0; i < num_de_thread; i++)
    {
        double *tempo_thread;
        pthread_join(thread[i], (void **)&tempo_thread);
        tempo_total += *tempo_thread;

        free(p[i]);
        free(tempo_thread);

        char arq_aux[50];
        sprintf(arq_aux, "Codigo/Thread_tipo2/aux%d.txt", i + 1);

        contatenar_arquivos(DIRETORIO_RESULTADO, arq_aux);
        remove(arq_aux);

    }

    sprintf(resultado, "Tempo total: %f\n\n", tempo_total);

    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

}