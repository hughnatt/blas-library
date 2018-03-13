/*
 * RICM3 - Méthodes Numériques - 2018
 * ANCRENAZ Ariane - SAUTON Tanguy
 * C Implementation of BLAS routines
 */

#include "mnblas.h"
#include "math.h"

/*
 * cblas_?nrm2
 * Computes the Euclidean norm of a vector
 * res = ||x||
 *
 * Types = s / d / sc / dz 
 */ 

float mncblas_snrm2(const int n, const float *x, const int incX)
{
    float nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        nrm += powf(x[i],2.0);
        nrm += powf(x[i + incX],2.0);
        nrm += powf(x[i + 2*incX],2.0);
        nrm += powf(x[i + 3*incX],2.0);
    }

    return sqrtf(nrm);
}

double mncblas_dnrm2(const int n, const double *x, const int incX)
{
    double nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        nrm += pow(x[i],2.0);
        nrm += pow(x[i + incX],2.0);
        nrm += pow(x[i + 2*incX],2.0);
        nrm += pow(x[i + 3*incX],2.0);
    }

    return sqrt(nrm);
}

float mncblas_scnrm2(const int n, const void *x, const int incX)
{
    cplx_t *array_x = (cplx_t *)x;

    float nrm;
    float cplx_nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        cplx_nrm = sqrtf(powf(array_x[i].re, 2.0) + powf(array_x[i].im, 2.0));
        nrm += powf(cplx_nrm, 2.0);

        cplx_nrm = sqrtf(powf(array_x[i + 1*incX].re, 2.0) + powf(array_x[i + 1*incX].im, 2.0));
        nrm += powf(cplx_nrm, 2.0);

        cplx_nrm = sqrtf(powf(array_x[i + 2*incX].re, 2.0) + powf(array_x[i + 2*incX].im, 2.0));
        nrm += powf(cplx_nrm, 2.0);

        cplx_nrm = sqrtf(powf(array_x[i + 3*incX].re, 2.0) + powf(array_x[i + 3*incX].im, 2.0));
        nrm += powf(cplx_nrm, 2.0);
    }

    return sqrtf(nrm);
}

double mncblas_dznrm2(const int n, const void *x, const int incX)
{
    cplx_t *array_x = (cplx_t *)x;

    double nrm;
    double cplx_nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        cplx_nrm = sqrt(powf(array_x[i].re, 2.0) + powf(array_x[i].im, 2.0));
        nrm += pow(cplx_nrm, 2.0);

        cplx_nrm = sqrt(powf(array_x[i + 1*incX].re, 2.0) + powf(array_x[i + 1*incX].im, 2.0));
        nrm += pow(cplx_nrm, 2.0);

        cplx_nrm = sqrt(powf(array_x[i + 2*incX].re, 2.0) + powf(array_x[i + 2*incX].im, 2.0));
        nrm += pow(cplx_nrm, 2.0);

        cplx_nrm = sqrt(powf(array_x[i + 3*incX].re, 2.0) + powf(array_x[i + 3*incX].im, 2.0));
        nrm += pow(cplx_nrm, 2.0);
    }

    return sqrt(nrm);
}
