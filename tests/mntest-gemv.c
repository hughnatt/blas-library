#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"

// ### Mesures des cycles
#include <x86intrin.h>


void mn_gemv_test_all(){

    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES GEMV @@@
    // @@@@@@@@@@@@@@@@@@@@@
    
}