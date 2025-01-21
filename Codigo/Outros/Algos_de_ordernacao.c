#include "Algos_de_ordernacao.h"


void printar_vetor(int *vetor, int num_de_numb)
{
    for (int i = 0; i < num_de_numb; i++)
    {
        printf("%d\n", vetor[i]);
    }
    
}


void quick_sort_recursive(int *vetor, int left, int right)
{
    if (left >= right)
        return;

    int pivo = vetor[(left + right) / 2];
    int i = left, j = right;
    while (i <= j)
    {
        while (vetor[i] < pivo)
            i++;
        while (vetor[j] > pivo)
            j--;
        if (i <= j)
        {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort_recursive(vetor, left, j);
    quick_sort_recursive(vetor, i, right);
}

void quick_sort(int *vetor, int num_de_numb)
{
    quick_sort_recursive(vetor, 0, num_de_numb - 1);
}

void selection_sort(int *vetor, int num_de_numb)
{
    int i, j, min, aux;
    for (i = 0; i < num_de_numb-1; i++)
    {
        min = i;
        for (j = i+1; j < num_de_numb; j++)
        {
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}


void Preencher_vetor_arquivo(FILE *arquivo, int num_de_numb, int *vetor)
{
    for (int i = 0; i < num_de_numb; i++)
    {
        fscanf(arquivo, "%d\n", &vetor[i]);
    }
    
}