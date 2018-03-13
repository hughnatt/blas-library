#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"

// ### Mesures des cycles
#include <x86intrin.h>


void mn_nrm2_test_all(){

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
    // @@@ ROUTINE nrm2 @@@
    // @@@@@@@@@@@@@@@@@@@@

    // --- snrm2 ---

    cblas_snrm2(VECSIZE, V1, 1);

    start = _rdtsc();
    mncblas_snrm2(VECSIZE, V1, 1);
    end = _rdtsc();
    printf("mnblas_snrm2: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_snrm2(VECSIZE, V1, 1);
    end = _rdtsc();
    printf("cblas_snrm2: nombre de cycles: %Ld \n", end - start - residu);   

    // --- scnrm2 ---
    cblas_scnrm2(VECSIZE, (float*) V2, 1);

    start = _rdtsc();
    mncblas_scnrm2(VECSIZE, V2, 1);
    end = _rdtsc();
    printf("mnblas_scnrm2: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_scnrm2(VECSIZE, (float*) V2, 1);
    end = _rdtsc();
    printf("cblas_scnrm2: nombre de cycles: %Ld \n", end - start - residu);   
   
    // --- dnrm2 ---
    cblas_dnrm2(VECSIZE, V3, 1);

    start = _rdtsc();
    mncblas_dnrm2(VECSIZE, V3, 1);
    end = _rdtsc();
    printf("mnblas_dnrm2: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dnrm2(VECSIZE, V3, 1);
    end = _rdtsc();
    printf("cblas_dnrm2: nombre de cycles: %Ld \n", end - start - residu);   
    
    // --- dznrm2 ---
    cblas_dznrm2(VECSIZE, (double*) V4, 1);

    start = _rdtsc();
    mncblas_dznrm2(VECSIZE, V4, 1);
    end = _rdtsc();
    printf("mnblas_dznrm2: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dznrm2(VECSIZE,(double*)  V4, 1);
    end = _rdtsc();
    printf("cblas_dznrm2: nombre de cycles: %Ld \n", end - start - residu); 
}