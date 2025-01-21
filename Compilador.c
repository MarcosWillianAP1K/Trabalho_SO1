#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("gcc -o ../Executavel -pthread ../Codigo/main.c ../Codigo/Outros/Cronometro.c ../Codigo/Outros/Escrever_resultado.c ../Codigo/Outros/Algos_de_ordernacao.c ../Codigo/Codigo_simples/Soma_numeros_simples.c ../Codigo/Arquivos_de_teste/gerador_de_testes.c ../Codigo/Codigo_simples/Organizacao_simples.c ../Codigo/Codigo_2_threads/Soma_2_thread.c ../Codigo/Codigo_2_threads/Organizacao_2_thread.c");
    system("cd .. && Executavel");

    return 0;

}