#include "mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX,
                   float *Y, const int incY)
{
    register unsigned int i = 0;
    register unsigned int j = 0;

    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        Y[j] = X[i];
    }

    return;
}

void mncblas_dcopy(const int N, const double *X, const int incX,
                   double *Y, const int incY)
{
    register unsigned int i = 0;
    register unsigned int j = 0;

    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        Y[j] = X[i];
    }

    return;
}

void mncblas_ccopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
    cplx_t** array_x = (cplx_t**) X;
    cplx_t** array_y = (cplx_t**) Y;


    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        array_y[j]->re = array_x[i]->re;
        array_y[j]->im = array_x[i]->im;
    }

    return;
}

void mncblas_zcopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
    cplxd_t** array_x = (cplxd_t**) X;
    cplxd_t** array_y = (cplxd_t**) Y;


    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        array_y[j]->re = array_x[i]->re;
        array_y[j]->im = array_x[i]->im;
    }

    return;
}
