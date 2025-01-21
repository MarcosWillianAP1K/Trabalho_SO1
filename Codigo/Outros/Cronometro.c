#include "Cronometro.h"

clock_t cronometro_iniciar()
{
    return clock();
}

clock_t cronometro_finalizar(clock_t inicio)
{
    clock_t fim = clock();
    
    return fim - inicio;
}


double converter_para_segundos(clock_t tempo)
{
    return ((double)tempo) / CLOCKS_PER_SEC;
}
