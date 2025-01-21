#include "Soma_multi_thread.h"






void soma_multi_thread_abrir_arquivo(int num_de_arq, int num_de_numb, int num_de_thread) 
{

    if (num_de_thread < 1 || num_de_thread > 1000 || num_de_arq < 1 || num_de_numb < 1) 
    {
        printf("Numero de threads invalido\n");
        exit(1);
    }

    FILE *arquivo;
    double tempo_total = 0;
    char resultado[100];
    #define DIRETORIO_RESULTADO "Resultados/Result_soma_multi_thread.txt"
    
    criar_resetar_arquivo(DIRETORIO_RESULTADO);

    sprintf(resultado, "Soma simples:\n\nCom %d arquivos.\nCada arquivo com %d numeros\n\n", num_de_arq, num_de_numb);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

    for (int i = 0; i < num_de_arq; i++)
    {
        

        char nome_arquivo[100];
        sprintf(nome_arquivo, "Codigo/Arquivos_de_teste/testes/teste_%d.txt", i+1);
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

        tempo_total += tempo;

        sprintf(nome_arquivo, "teste_%d.txt", i+1);

        sprintf(resultado, "%s: Tempo de duracao: %f\n", nome_arquivo, tempo);
        
        escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

        // printf("Soma do arquivo %s: %d\n", nome_arquivo, soma);

        fclose(arquivo);
    }

    sprintf(resultado, "\nTempo total de duracao: %f\n", tempo_total);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);




}