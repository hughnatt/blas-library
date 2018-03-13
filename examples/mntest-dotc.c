#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

// ### Mesures des cycles
#include <x86intrin.h>

#include "mntest.h"


void mn_dotc_test_all(){

    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    vcplx X1,Y1;
    vcplx_rand(X1);
    vcplx_rand(Y1);
    
    vcplxd X2, Y2;
    vcplxd_rand(X2);
    vcplxd_rand(Y2);

    Complex_c dot1;
    Complex_z dot2;

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES DOTC @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- cdotc_sub
    start = _rdtsc();
    cblas_cdotc_sub(VECSIZE,(float*) X1,1,(float*) Y1,1,(_Complex float*) &dot1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_cdotc_sub(VECSIZE,X1,1,Y1,1,&dot1);
    end = _rdtsc();
    printf("mnblas_cdotc: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_cdotc_sub(VECSIZE,(float*) X1,1,(float*) Y1,1, (_Complex float*) &dot1);
    end = _rdtsc();
    printf("cblas_cdotc: nombre de cycles: %Ld \n", end - start - residu);   

    // --- zdotc_sub
    start = _rdtsc();
    cblas_zdotc_sub(VECSIZE,(double*) X2,1,(double*) Y2,1,(_Complex double*) &dot2);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_zdotc_sub(VECSIZE,X2,1,Y2,1,&dot2);
    end = _rdtsc();
    printf("mnblas_zdotc: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_zdotc_sub(VECSIZE,(double*) X2,1,(double*) Y2,1,(_Complex double*) &dot2);
    end = _rdtsc();
    printf("cblas_zdotc: nombre de cycles: %Ld \n", end - start - residu);   


    
}