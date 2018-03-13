#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

// ### Mesures des cycles
#include <x86intrin.h>

#include "mntest.h"


void mn_asum_test_all(){

    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    vfloat V1;
    vfloat_rand(V1);
    vcplx V2;
    vcplx_rand(V2);
    vdouble V3;
    vdouble_rand(V3);
    vcplxd V4;
    vcplxd_rand(V4);

    // @@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINE ASUM @@@
    // @@@@@@@@@@@@@@@@@@@@

    // --- sasum ---

    cblas_sasum(VECSIZE, V1, 1);

    start = _rdtsc();
    mncblas_sasum(VECSIZE, V1, 1);
    end = _rdtsc();
    printf("mnblas_sasum: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_sasum(VECSIZE, V1, 1);
    end = _rdtsc();
    printf("cblas_sasum: nombre de cycles: %Ld \n", end - start - residu);   

    // --- scasum ---
    cblas_scasum(VECSIZE, (float*) V2, 1);

    start = _rdtsc();
    mncblas_scasum(VECSIZE, (void*) V2, 1);
    end = _rdtsc();
    printf("mnblas_scasum: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_scasum(VECSIZE, (float*) V2, 1);
    end = _rdtsc();
    printf("cblas_scasum: nombre de cycles: %Ld \n", end - start - residu);   
   
    // --- dasum ---
    cblas_dasum(VECSIZE, V3, 1);

    start = _rdtsc();
    mncblas_dasum(VECSIZE, V3, 1);
    end = _rdtsc();
    printf("mnblas_dasum: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dasum(VECSIZE, V3, 1);
    end = _rdtsc();
    printf("cblas_dasum: nombre de cycles: %Ld \n", end - start - residu);   
    
    // --- dzasum ---
    cblas_dzasum(VECSIZE, (double*) V4, 1);

    start = _rdtsc();
    mncblas_dzasum(VECSIZE,(void*) V4, 1);
    end = _rdtsc();
    printf("mnblas_dzasum: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dzasum(VECSIZE, (double*) V4, 1);
    end = _rdtsc();
    printf("cblas_dzasum: nombre de cycles: %Ld \n", end - start - residu);
}