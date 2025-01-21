#include <time.h>
#include <stdio.h>
#include <stdlib.h>



#ifndef CRONOMETRO_H
#define CRONOMETRO_H

clock_t cronometro_iniciar();


clock_t cronometro_finalizar(clock_t inicio);



double converter_para_segundos(clock_t tempo);

#endif

