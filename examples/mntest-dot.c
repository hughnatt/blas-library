#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"

// ### Mesures des cycles
#include <x86intrin.h>


void mn_dot_test_all(){

    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    vfloat X1,Y1;
    vfloat_rand(X1);
    vfloat_rand(Y1);
    
    vdouble X2,Y2;
    vdouble_rand(X2);
    vdouble_rand(Y2);

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES DOT  @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- sdot
    
    start = _rdtsc();
    cblas_sdot(VECSIZE,X1,1,Y1,1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_sdot(VECSIZE,X1,1,Y1,1);
    end = _rdtsc();
    printf("mnblas_sdot: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_sdot(VECSIZE,X1,1,Y1,1);
    end = _rdtsc();
    printf("cblas_sdot: nombre de cycles: %Ld \n", end - start - residu);   

    // --- ddot

    start = _rdtsc();
    cblas_ddot(VECSIZE,X2,1,Y2,1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_ddot(VECSIZE,X2,1,Y2,1);
    end = _rdtsc();
    printf("mnblas_ddot: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_ddot(VECSIZE,X2,1,Y2,1);
    end = _rdtsc();
    printf("cblas_ddot: nombre de cycles: %Ld \n", end - start - residu);  
}