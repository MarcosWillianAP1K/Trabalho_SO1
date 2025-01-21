#include "Arquivos_de_teste/gerador_de_testes.h"

#include "Sem_threads/Soma_numeros_simples.h"
#include "Sem_threads/Organizacao_simples.h"

#include "Threads_tipo1/Organizacao_threads_1.h"
#include "Threads_tipo1/Soma_threads_1.h"

#include "Thread_tipo2/Soma_threads_2.h"
#include  "Thread_tipo2/Organizacao_threads_2.h"

#define NUM_DE_ARQUIVOS 10
#define NUM_POR_ARQUIVOS 100


int main()
{
    // printf("Gerando arquivos\n");
    // gerar_arquivos(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Arquivos gerados com sucesso\n\n");


    /* 
        EXECUÇÃO DOS CODIGOS SIMPLES
    */

    // printf("Soma simples iniciada\n");
    // Soma_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Soma simples finalizada\n\n");

    // printf("Organizacao simples iniciada\n");
    // Organizacao_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Organizacao simples finalizada\n\n");


    /* 
        EXECUÇÃO DOS CODIGOS THREADS TIPO 1
    */

    printf("Soma thread tipo 1 iniciada\n");
    Soma_thread_1_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, 3);
    printf("Soma thread tipo 1 finalizada\n\n");

    printf("Organizacao thread tipo 1 iniciada\n");
    Organizacao_thread_1_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, 3);
    printf("Organizacao thread tipo 1 finalizada\n\n");


    /* 
        EXECUÇÃO DOS CODIGOS THREADS TIPO 2
    */

    // printf("Soma thread tipo 2 iniciada\n");
    // Soma_threads_2_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, 2);
    // printf("Soma thread tipo 2 finalizada\n\n");

    // printf("Organizacao thread tipo 2 iniciada\n");
    // Organizacao_threads_2_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS, 3);
    // printf("Organizacao thread tipo 2 finalizada\n\n");
    


    return 0;
}