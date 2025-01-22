#include "Organizacao_simples.h"
#include "../Outros/Cronometro.h"
#include "../Outros/Escrever_resultado.h"
#include "../Outros/Algos_de_ordernacao.h"




void Organizacao_simples_abrir_arquivo(int num_de_arq, int num_de_numb)
{
    
    FILE *arquivo;
    char resultado[100];
    double tempo_total = 0;
    #define DIRETORIO_RESULTADO "Resultados/Result_organizacao_simples.txt"

    criar_resetar_arquivo(DIRETORIO_RESULTADO);

    sprintf(resultado, "Organizacao simples:\n\nCom %d arquivos\nCada arquivo com %d numeros\n\n", num_de_arq, num_de_numb);
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

        int *vetor = (int *)malloc(num_de_numb * sizeof(int));

        clock_t cronometro = cronometro_iniciar();

        Preencher_vetor_arquivo(arquivo, num_de_numb, vetor);
        
        cronometro = cronometro_finalizar(cronometro);

        double tempo = converter_para_segundos(cronometro);

        tempo_total += tempo;
        sprintf(nome_arquivo, "teste_%d.txt", i+1);

        sprintf(resultado, "%s: Tempo de preencher: %f   ", nome_arquivo, tempo);
        escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

        cronometro = cronometro_iniciar();
        quick_sort(vetor, num_de_numb);
        cronometro = cronometro_finalizar(cronometro);

        tempo = converter_para_segundos(cronometro);

        tempo_total += tempo;

        sprintf(resultado, "Tempo de organizacao: %f\n", tempo);
        escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

        // printar_vetor(vetor, num_de_numb);
        // system("pause");
       

        free(vetor);
        fclose(arquivo);
    }

    sprintf(resultado, "\nTempo total de duracao: %f\n", tempo_total);
    escrever_resultado_anexar(DIRETORIO_RESULTADO, resultado);

}
