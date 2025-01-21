#include "Escrever_resultado.h"


void criar_resetar_arquivo(char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    fclose(arquivo);
}


void escrever_resultado_anexar(char *nome_arquivo, char *informacao)
{
    FILE *arquivo = fopen(nome_arquivo, "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    fprintf(arquivo, "%s", informacao);

    fclose(arquivo);
}
