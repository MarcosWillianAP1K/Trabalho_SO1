#include "Escrever_resultado.h"


void contatenar_arquivos(char *arquivo1, char *arquivo2)
{
    FILE *arq1 = fopen(arquivo1, "a");
    FILE *arq2 = fopen(arquivo2, "r");

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("Erro ao abrir o arquivo %s ou %s\n", arquivo1, arquivo2);
        exit(1);
    }

    char c;

    while ((c = fgetc(arq2)) != EOF)
    {
        fputc(c, arq1);
    }

    fclose(arq1);
    fclose(arq2);
}


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
