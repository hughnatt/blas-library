/*
 * RICM3 - Méthodes Numériques - 2018
 * ANCRENAZ Ariane - SAUTON Tanguy
 * C Implementation of BLAS routines
 */

#include "mnblas.h"

/*
 * cblas_?dot
 * Computes a vector-vector dot product
 * res = SUM(i from 1 to N){Xi * Yi}
 * 
 * Types : s / d
 */

float mncblas_sdot(const int N, const float *X, const int incX,
                   const float *Y, const int incY)
{
    register float dot = 0.0;

    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        dot += X[i] * Y[j];
        dot += X[i + 1*incX] * Y[j + 1*incY];
        dot += X[i + 2*incX] * Y[j + 2*incY];
        dot += X[i + 3*incX] * Y[j + 3*incY];
    }

    return dot;
}

double mncblas_ddot(const int N, const double *X, const int incX,
                    const double *Y, const int incY)
{
    register double dot = 0.0;

    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        dot += X[i] * Y[j];
        dot += X[i + 1*incX] * Y[j + 1*incY];
        dot += X[i + 2*incX] * Y[j + 2*incY];
        dot += X[i + 3*incX] * Y[j + 3*incY];
    }

    return dot;
}
