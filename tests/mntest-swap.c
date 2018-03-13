#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"

// ### Mesures des cycles
#include <x86intrin.h>

void mn_swap_test_all()
{

    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    vfloat X1, Y1;
    vfloat_rand(X1);
    vfloat_rand(Y1);

    vdouble X2, Y2;
    vdouble_rand(X2);
    vdouble_rand(Y2);

    vcplx X3, Y3;
    vcplx_rand(X3);
    vcplx_rand(Y3);

    vcplxd X4, Y4;
    vcplxd_rand(X4);
    vcplxd_rand(Y4);

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES swap @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- sswap

    cblas_sswap(VECSIZE, X1, 1, Y1, 1);

    start = _rdtsc();
    mncblas_sswap(VECSIZE, X1, 1, Y1, 1);
    end = _rdtsc();
    printf("mncblas_sswap: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_sswap(VECSIZE, X1, 1, Y1, 1);
    end = _rdtsc();
    printf("cblas_sswap nombre de cycles cblas: %Ld \n", end - start - residu);

    // --- dswap

    cblas_dswap(VECSIZE, X2, 1, Y2, 1);

    start = _rdtsc();
    mncblas_dswap(VECSIZE, X2, 1, Y2, 1);
    end = _rdtsc();
    printf("mncblas_dswap: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_dswap(VECSIZE, X2, 1, X2, 1);
    end = _rdtsc();
    printf("cblas_dswap nombre de cycles cblas: %Ld \n", end - start - residu);

    // --- cswap

    cblas_cswap(VECSIZE, (float *)X3, 1, (float *)Y3, 1);

    start = _rdtsc();
    mncblas_cswap(VECSIZE, X3, 1, Y3, 1);
    end = _rdtsc();
    printf("mncblas_cswap: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_cswap(VECSIZE, (float *)X3, 1, (float *)Y3, 1);
    end = _rdtsc();
    printf("cblas_cswap nombre de cycles cblas: %Ld \n", end - start - residu);

    // --- zswap
    cblas_zswap(VECSIZE, (double *)X4, 1, (double *)Y4, 1);

    start = _rdtsc();
    mncblas_zswap(VECSIZE, X4, 1, Y4, 1);
    end = _rdtsc();
    printf("mncblas_zswap: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_zswap(VECSIZE, (double *)X4, 1, (double *)Y4, 1);
    end = _rdtsc();
    printf("cblas_zswap nombre de cycles cblas: %Ld \n", end - start - residu);
}