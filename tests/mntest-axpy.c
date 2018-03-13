#include <stdio.h>
// ### Fonctions BLAS Intel
#include <cblas.h>
// ### Fonctions BLAS MN Perso
#include "mnblas.h"

#include "mntest.h"
// ### Mesures des cycles
#include <x86intrin.h>


void mn_axpy_test_all(){

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
    // @@@ ROUTINES AXPY @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- saxpy
    start = _rdtsc();
    cblas_saxpy(VECSIZE,3.14,X1,1,Y1,1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_saxpy(VECSIZE,3.14,X1,1,Y1,1);
    end = _rdtsc();
    printf("mnblas_saxpy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_saxpy(VECSIZE,3.14,X1,1,Y1,1);
    end = _rdtsc();
    printf("cblas_saxpy: nombre de cycles: %Ld \n", end - start - residu);   

    // --- daxpy
     start = _rdtsc();
    cblas_daxpy(VECSIZE,3.14,X2,1,Y2,1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_daxpy(VECSIZE,3.14,X2,1,Y2,1);
    end = _rdtsc();
    printf("mnblas_daxpy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_daxpy(VECSIZE,3.14,X2,1,Y2,1);
    end = _rdtsc();
    printf("cblas_daxpy: nombre de cycles: %Ld \n", end - start - residu);

    // --- caxpy
    Complex_c alpha;
    alpha.re = 2.0;
    alpha.im = 6.0;

     start = _rdtsc();
    cblas_caxpy(VECSIZE,(float*) &alpha,(float*) X3,1,(float*) Y3,1);
    end = _rdtsc();

    start = _rdtsc();
    mncblas_caxpy(VECSIZE, (void*) &alpha,X3,1,Y3,1);
    end = _rdtsc();
    printf("mnblas_caxpy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_caxpy(VECSIZE,(float*) &alpha,(float*) X3,1, (float*) Y3,1);
    end = _rdtsc();
    printf("cblas_caxpy: nombre de cycles: %Ld \n", end - start - residu);
    
    // --- zaxpy
    Complex_z beta;
    beta.re = 2.0;
    beta.im = 6.0;
    
    start = _rdtsc();
    cblas_zaxpy(VECSIZE,(double*) &beta,(double*) X4,1,(double*) Y4,1);
    end = _rdtsc();
    
    start = _rdtsc();
    mncblas_zaxpy(VECSIZE,(void*) &beta,X4,1,Y4,1);
    end = _rdtsc();
    printf("mnblas_zaxpy: nombre de cycles: %Ld \n", end - start - residu);

    start = _rdtsc();
    cblas_zaxpy(VECSIZE,(double*) &beta,(double*) X4,1,(double*) Y4,1);
    end = _rdtsc();
    printf("cblas_zaxpy: nombre de cycles: %Ld \n", end - start - residu);
}