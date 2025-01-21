#include "Codigo_simples/Soma_numeros_simples.h"
#include "Codigo_simples/Organizacao_simples.h"
#include "Arquivos_de_teste/gerador_de_testes.h"
#include "Codigo_2_threads/Soma_2_thread.h"
#include "Codigo_2_threads/Organizacao_2_thread.h"

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
    // soma_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Soma simples finalizada\n\n");

    // printf("Organizacao simples iniciada\n");
    // Organizacao_simples_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Organizacao simples finalizada\n\n");


    /* 
        EXECUÇÃO DOS CODIGOS COM 2 THREADS
    */

    // printf("Soma 2 thread iniciada\n");
    // soma_2_thread_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    // printf("Soma 2 thread finalizada\n\n");

    printf("Organizacao 2 thread iniciada\n");
    Organizacao_2_thread_abrir_arquivo(NUM_DE_ARQUIVOS, NUM_POR_ARQUIVOS);
    printf("Organizacao 2 thread finalizada\n\n");

    


    return 0;
}