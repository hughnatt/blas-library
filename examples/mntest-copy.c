#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"

// ### Mesures des cycles
#include <x86intrin.h>



void mn_copy_test_all(){

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
    
    vcplx X3,Y3;
    vcplx_rand(X3);
    vcplx_rand(Y3);
    
    vcplxd X4, Y4;
    vcplxd_rand(X4);
    vcplxd_rand(Y4);

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES COPY @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- scopy
    
    cblas_scopy(VECSIZE, X1, 1, Y1, 1);

    start = _rdtsc();
    mncblas_scopy(VECSIZE, X1, 1, Y1, 1);
    end = _rdtsc();
    printf("mncblas_scopy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_scopy(VECSIZE, X1, 1, Y1, 1);
    end = _rdtsc();
    printf("cblas_scopy nombre de cycles cblas: %Ld \n", end - start - residu);   

    // --- dcopy

    cblas_dcopy(VECSIZE, X2, 1, Y2, 1);

    start = _rdtsc();
    mncblas_dcopy(VECSIZE, X2, 1, Y2, 1);
    end = _rdtsc();
    printf("mncblas_dcopy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dcopy(VECSIZE, X2, 1, X2, 1);
    end = _rdtsc();
    printf("cblas_dcopy nombre de cycles cblas: %Ld \n", end - start - residu);   
    
    // --- ccopy

    cblas_ccopy(VECSIZE, (float*) X3, 1, (float*) Y3, 1);

    start = _rdtsc();
    mncblas_ccopy(VECSIZE, X3, 1, Y3, 1);
    end = _rdtsc();
    printf("mncblas_ccopy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_ccopy(VECSIZE, (float*) X3, 1, (float*) Y3, 1);
    end = _rdtsc();
    printf("cblas_ccopy nombre de cycles cblas: %Ld \n", end - start - residu);   
    
    // --- zcopy
    cblas_zcopy(VECSIZE, (double*) X4, 1, (double*) Y4, 1);

    start = _rdtsc();
    mncblas_zcopy(VECSIZE, X4, 1, X4, 1);
    end = _rdtsc();
    printf("mncblas_zcopy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_zcopy(VECSIZE, (double*) X4, 1, (double*) Y4, 1);
    end = _rdtsc();
    printf("cblas_zcopy nombre de cycles cblas: %Ld \n", end - start - residu);   
}