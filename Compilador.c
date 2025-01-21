#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("gcc -o ../Executavel -pthread ../Codigo/main.c ../Codigo/Arquivos_de_teste/gerador_de_testes.c ../Codigo/Outros/Cronometro.c ../Codigo/Outros/Escrever_resultado.c ../Codigo/Outros/Algos_de_ordernacao.c ../Codigo/Sem_threads/Soma_numeros_simples.c ../Codigo/Sem_threads/Organizacao_simples.c ../Codigo/Threads_tipo1/Organizacao_threads_1.c ../Codigo/Threads_tipo1/Soma_threads_1.c ../Codigo/Thread_tipo2/Soma_threads_2.c ../Codigo/Thread_tipo2/Organizacao_threads_2.c");
    system("cd .. && Executavel");

    return 0;

}