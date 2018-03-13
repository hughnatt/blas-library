#include <stdio.h>
#include <time.h>

// ### Fonctions BLAS Intel
#include <cblas.h>

// ### Fonctions BLAS MN Perso
#include "mnblas.h"

// ### Mesures des cycles
#include <x86intrin.h>

#include "mntest.h"

/*
 * Initialisation d'un @vector avec une valeur fixe x
 */
void vfloat_init(vfloat V, float x)
{
    register unsigned int i;
    for (i = 0; i < VECSIZE; i++)
        V[i] = x;
}
void vdouble_init(vdouble V, double x)
{
    register unsigned int i;
    for (i = 0; i < VECSIZE; i++)
        V[i] = x;
}
void vcplx_init(vcplx V, Complex_c x)
{
    for (int i = 0; i < VECSIZE; i++)
    {
        V[i].re = x.re;
        V[i].im = x.im;
    }
}
void vcplxd_init(vcplxd V, Complex_z x)
{
    for (int i = 0; i < VECSIZE; i++)
    {
        V[i].re = x.re;
        V[i].im = x.im;
    }
}

/*
 * initialisation d'un @vector avec une valeur fixe aléatoire
 */
void vfloat_rand(vfloat V)
{
    register unsigned int i;
    for (i = 0; i < VECSIZE; i++)
        V[i] = (float)rand();
}
void vdouble_rand(vdouble V)
{
    register unsigned int i;
    for (i = 0; i < VECSIZE; i++)
        V[i] = (double)rand();
}
void vcplx_rand(vcplx V)
{
    for (int i = 0; i < VECSIZE; i++)
    {
        V[i].re = (float)rand();
        V[i].im = (float)rand();
    }
}
void vcplxd_rand(vcplxd V)
{
    for (int i = 0; i < VECSIZE; i++)
    {
        V[i].re = (double)rand();
        V[i].im = (double)rand();
    }
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
    srand(time(NULL));

    mn_asum_test_all();
    mn_axpy_test_all();
    mn_copy_test_all();
    mn_dot_test_all();
    mn_dotc_test_all();
    mn_dotu_test_all();
    mn_gemm_test_all();
    mn_gemv_test_all();
    mn_nrm2_test_all();
    mn_swap_test_all();

}
