#include <stdlib.h>
#include "mnblas.h"

float cblas_sasum(const int n, const float *x, const int incx)
{

    float asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incx)
    {
        asum += abs(x[i]);
    }
    return asum;
}

float cblas_scasum(const int n, const void *x, const int incx)
{
    cplx_t **c = (cplx_t **)(x);
    
    float asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incx)
    {
        asum = asum + abs(c[i]->re) + abs(c[i]->im);
    }
    return asum;
}

double cblas_dasum(const int n, const double *x, const int incx)
{
    register unsigned int i = 0;
    double asum = 0.0;

    for (; (i < n); i += incx)
    {
        asum += abs(x[i]);
    }
    return asum;
}

double cblas_dzasum(const int n, const void *x, const int incx)
{
    cplx_t **c = (cplx_t **)(x);
    
    double asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incx)
    {
        asum = asum + abs(c[i]->re) + abs(c[i]->im);
    }
    return asum;
}