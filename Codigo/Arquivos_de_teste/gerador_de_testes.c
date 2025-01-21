#include "gerador_de_testes.h"
#include <time.h>




void preencher_aleatorio_arquivo(FILE *arquivo, int num_de_numb)
{
    
    for (int i = 0; i < num_de_numb; i++)
    {
        fprintf(arquivo, "%d\n", (rand() % num_de_numb) + 1);
    }
}

void preencher_sequencial_crescente_arquivo(FILE *arquivo, int num_de_numb)
{
    for (int i = 0; i < num_de_numb; i++)
    {
        fprintf(arquivo, "%d\n", i+1);
    }
}

void preencher_sequencial_decrescente_arquivo(FILE *arquivo, int num_de_numb)
{
    for (int i = num_de_numb; i > 0; i--)
    {
        fprintf(arquivo, "%d\n", i);
    }
}

void gerar_arquivos(int num_de_arq, int num_de_numb)
{
    srand(time(NULL));
    FILE *arq = NULL;

    for(int i = 0; i < num_de_arq; i++)
    {

        
        char nome_arquivo[100];
        sprintf(nome_arquivo, "Codigo/Arquivos_de_teste/testes/teste_%d.txt", i+1);
        arq = fopen(nome_arquivo, "w");

        if (arq == NULL)
        {
            printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
            exit(1);
        }

        if (i == 0)
        {
            preencher_sequencial_crescente_arquivo(arq, num_de_numb);
        }
        else if (i == 1)
        {
            preencher_sequencial_decrescente_arquivo(arq, num_de_numb);
        }
        else
        {
            preencher_aleatorio_arquivo(arq, num_de_numb);
        }

        
        fclose(arq);
    }

    

}

