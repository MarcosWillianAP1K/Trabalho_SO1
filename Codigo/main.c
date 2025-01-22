#include "Arquivos_de_teste/gerador_de_testes.h"

#include "Sem_threads/Soma_numeros_simples.h"
#include "Sem_threads/Organizacao_simples.h"

#include "Threads_tipo1/Organizacao_threads_1.h"
#include "Threads_tipo1/Soma_threads_1.h"

#include "Thread_tipo2/Soma_threads_2.h"
#include "Thread_tipo2/Organizacao_threads_2.h"

#include <stdbool.h>


/*
ATENÇÃO: 
    - O código foi feito para suportar ate 10 threads e no minimo 1 thread.
    -Para mais que isso requer modificações nos algoritmos (no caso apenas nas condições).
*/

#define NUM_DE_ARQUIVOS 100
#define NUM_POR_ARQUIVOS 1000000
#define NUM_DE_THREADS 2
#define GERAR_ARQUIVOS true

int main()
{
    if (GERAR_ARQUIVOS)
    {
        printf("Gerando arquivos\n");
        gerar_arquivos(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
        printf("Arquivos gerados com sucesso\n\n");
    }

    printf("Iniciando execucao dos codigos\n\nCom %d threads.\nE %d arquivos.\nCada arquivo com %d numeros.\n\n", NUM_DE_THREADS,NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);


    /*
        EXECUÇÃO DOS CODIGOS SIMPLES
    */

    printf("Soma simples iniciada\n");
    Soma_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    printf("Soma simples finalizada\n\n");

    printf("Organizacao simples iniciada\n");
    Organizacao_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    printf("Organizacao simples finalizada\n\n");

    /*
        EXECUÇÃO DOS CODIGOS THREADS TIPO 1
    */

    printf("Soma thread tipo 1 iniciada\n");
    Soma_thread_1_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, NUM_DE_THREADS);
    printf("Soma thread tipo 1 finalizada\n\n");

    printf("Organizacao thread tipo 1 iniciada\n");
    Organizacao_thread_1_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, NUM_DE_THREADS);
    printf("Organizacao thread tipo 1 finalizada\n\n");

    /*
        EXECUÇÃO DOS CODIGOS THREADS TIPO 2
    */

    printf("Soma thread tipo 2 iniciada\n");
    Soma_threads_2_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, NUM_DE_THREADS);
    printf("Soma thread tipo 2 finalizada\n\n");

    printf("Organizacao thread tipo 2 iniciada\n");
    Organizacao_threads_2_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, NUM_DE_THREADS);
    printf("Organizacao thread tipo 2 finalizada\n\n");

    return 0;
}