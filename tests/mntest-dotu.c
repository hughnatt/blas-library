#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"
// ### Mesures des cycles
#include <x86intrin.h>


#include "mntest.h"


void mn_dotu_test_all(){

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
    // @@@ ROUTINES DOTU @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- cdotu_sub
    start = _rdtsc();
    cblas_cdotu_sub(VECSIZE,(float*) X1,1,(float*)Y1,1,(_Complex float*)&dot1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_cdotu_sub(VECSIZE,X1,1,Y1,1,&dot1);
    end = _rdtsc();
    printf("mnblas_cdotu: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_cdotu_sub(VECSIZE,(float*)X1,1,(float*)Y1,1,(_Complex float*)&dot1);
    end = _rdtsc();
    printf("cblas_cdotu: nombre de cycles: %Ld \n", end - start - residu);   

    // --- zdotu_sub
    start = _rdtsc();
    cblas_zdotu_sub(VECSIZE,(double*) X2,1,(double*) Y2,1,(_Complex double*)&dot2);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_zdotu_sub(VECSIZE,X2,1,Y2,1,&dot2);
    end = _rdtsc();
    printf("mnblas_zdotu: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_zdotu_sub(VECSIZE,(double*) X2,1,(double*) Y2,1,(_Complex double*)&dot2);
    end = _rdtsc();
    printf("cblas_zdotu: nombre de cycles: %Ld \n", end - start - residu);   

}