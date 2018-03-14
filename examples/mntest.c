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
vfloat vec_1, vec_2;

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
void vector_print(cplx_t* V,int n)
{
    register unsigned int i;

    for (i = 0; i < n; i++)
        printf("%f + i%f--", V[i].re,V[i].im);
    printf("\n");

    return;
}

/*
 * Entry Point
 */
int main(int argc, char **argv)
{
    /*unsigned long long start, end;
    unsigned long long residu;

    // Calcul du residu de la mesure
    start = _rdtsc();
    end = _rdtsc();
    residu = end - start;

    // Initialisation vec1, valeur : 1.0
    vector_init(vec_1, 1.0);

    // @@@@@@@@@@@@@@@@@@@@@
    // @@@ ROUTINES COPY @@@
    // @@@@@@@@@@@@@@@@@@@@@
    
    // --- scopy ---
    start = _rdtsc();
    cblas_scopy(VECSIZE, vec_1, 1, vec_2, 1);
    end = _rdtsc();
    printf("cblas_scopy1 nombre de cycles cblas: %Ld \n", end - start - residu);
    
    start = _rdtsc();
    mncblas_scopy(VECSIZE, vec_1, 1, vec_2, 1);
    end = _rdtsc();
    printf("mncblas_scopy: nombre de cycles: %Ld \n", end - start - residu);
    
    printf ("Vector 2:\n") ;
    vector_print (vec2) ;
    

    start = _rdtsc();
    cblas_scopy(VECSIZE, vec_1, 1, vec_2, 1);
    end = _rdtsc();
    printf("cblas_scopy2 nombre de cycles cblas: %Ld \n", end - start - residu);*/


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


    cplx_t vecteur1[3];
    cplx_t vecteur2[2];

    vecteur1[0].re=3;
    vecteur1[1].re=2;
    vecteur1[2].re=1;
    vecteur2[0].re=2;
    vecteur2[1].re=4;

    vecteur1[0].im=3;
    vecteur1[1].im=3;
    vecteur1[2].im=1;
    vecteur2[0].im=4;
    vecteur2[1].im=2;

    vector_print(vecteur1,3);
    vector_print(vecteur2,2);

    cplx_t a[6];
    a[0].re=1;
    a[1].re=3;
    a[2].re=2;
    a[3].re=1;
    a[4].re=2;
    a[5].re=3;

    a[0].im=-2;
    a[1].im=-1;
    a[2].im=-1;
    a[3].im=-3;
    a[4].im=-2;
    a[5].im=-2;

    float al,be;
    al = 1.0;
    be = 1.0;


    mncblas_cgemv(101,113,3,2,&al,a,2,vecteur1,1,&be,vecteur2,1);

    vector_print(vecteur2,2);


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
