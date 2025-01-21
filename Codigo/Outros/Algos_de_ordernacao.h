#include <stdio.h>
#include <stdlib.h>

#ifndef ALGOS_DE_ORDENACAO_H
#define ALGOS_DE_ORDENACAO_H


void quick_sort(int *vetor, int num_de_numb);

void selection_sort(int *vetor, int num_de_numb);

void Preencher_vetor_arquivo(FILE *arquivo, int num_de_numb, int *vetor);

void printar_vetor(int *vetor, int num_de_numb);


#endif