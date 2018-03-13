#include <stdio.h>

// ### Fonctions BLAS Intel
#include <cblas.h>

// ### Fonctions BLAS MN Perso
#include "mnblas.h"

// ### Mesures des cycles
#include <x86intrin.h>

// ### Taille vecteur
#define VECSIZE 1000

/*
 *
 */

/*
 * Type vecteur : @vfloat 
 */
typedef float vfloat[VECSIZE];
vfloat vec1, vec2;

typedef cplx_t vcomplex[VECSIZE];
vcomplex vec1, vec2;
/*
 *
 */


/*
 * Initialisation d'un @vfloat avec une valeur fixe x
 */
void vector_init(vfloat V, float x)
{
    register unsigned int i;

    for (i = 0; i < VECSIZE; i++)
        V[i] = x;

    return;
}

/*
 * Affichage d'un @vfloat en console
 */
void vector_print(vfloat V)
{
    register unsigned int i;

    for (i = 0; i < VECSIZE; i++)
        printf("%f ", V[i]);
    printf("\n");

    return;
}

/*
 * Entry Point
 */
int main(int argc, char **argv)
{
    unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    // Initialisation vec1, valeur : 1.0
    vector_init(vec1, 1.0);

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES COPY @@@
    // @@@@@@@@@@@@@@@@@@@@@
    
    // --- scopy ---
    start = _rdtsc();
    cblas_scopy(VECSIZE, vec1, 1, vec2, 1);
    end = _rdtsc();
    printf("cblas_scopy1 nombre de cycles cblas: %Ld \n", end - start - residu);
    
    start = _rdtsc();
    mncblas_scopy(VECSIZE, vec1, 1, vec2, 1);
    end = _rdtsc();
    printf("mncblas_scopy: nombre de cycles: %Ld \n", end - start - residu);
    /* 
    printf ("Vector 2:\n") ;
    vector_print (vec2) ;
    */

    start = _rdtsc();
    cblas_scopy(VECSIZE, vec1, 1, vec2, 1);
    end = _rdtsc();
    printf("cblas_scopy2 nombre de cycles cblas: %Ld \n", end - start - residu);


    // @@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINE ASUM @@@
    // @@@@@@@@@@@@@@@@@@@@

    // --- sasum ---
    // --- scasum ---
    // --- dasum ---
    // --- dzasum ---

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES AXPY @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- saxpy
    // --- daxpy
    // --- caxpy
    // --- zaxpy

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES COPY @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- scopy
    // --- dcopy
    // --- ccopy
    // --- zcopy

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES DOT  @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- sdot
    // --- ddot

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES DOTC @@@
    // @@@@@@@@@@@@@@@@@@@@@
    
    // --- zdotc_sub
    // --- cdotc_sub

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES DOTU @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- zdotu_sub
    // --- cdotu_sub

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES GEMM @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES GEMV @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES NRM2 @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- snrm2
    // --- dnrm2
    // --- scnrm2
    // --- dznrm2

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES SWAP @@@
    // @@@@@@@@@@@@@@@@@@@@@

    // --- sswap
    // --- dswap
    // --- cswap
    // --- zswap
}
