#include "mnblas.h"

void mncblas_sswap(const int N, float *X, const int incX,
                   float *Y, const int incY)
{
    register float save;

    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX, j += incY*2)
    {
        save = Y[j];
        Y[j] = X[i];
        X[i] = save;
    }

    return;
}

void mncblas_dswap(const int N, double *X, const int incX,
                   double *Y, const int incY)
{
    register double save;

    register unsigned int i = 0;
    register unsigned int j = 0;

    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        save = Y[j];
        Y[j] = X[i];
        X[i] = save;
    }

    return;
}

void mncblas_cswap(const int N, void *X, const int incX,
                   void *Y, const int incY)
{
    cplx_t **array_x = (cplx_t **)X;
    cplx_t **array_y = (cplx_t **)Y;

    register unsigned int i = 0;
    register unsigned int j = 0;
    cplx_t save;

    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        save.re = array_y[j]->re;
        save.im = array_y[j]->im;

        array_y[j]->re = array_x[i]->im;
        array_y[j]->re = array_x[i]->im;

        array_x[i]->re = save.re;
        array_x[i]->im = save.im;
    }
}

void mncblas_zswap(const int N, void *X, const int incX,
                   void *Y, const int incY)
{
    cplxd_t **array_x = (cplxd_t **)X;
    cplxd_t **array_y = (cplxd_t **)Y;

    register unsigned int i = 0;
    register unsigned int j = 0;
    cplxd_t save;

    for (; ((i < N) && (j < N)); i += incX, j += incY)
    {
        save.re = array_y[j]->re;
        save.im = array_y[j]->im;

        array_y[j]->re = array_x[i]->im;
        array_y[j]->re = array_x[i]->im;

        array_x[i]->re = save.re;
        array_x[i]->im = save.im;
    }
}
