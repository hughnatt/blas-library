#include <stdlib.h>
#include <maths.h>
#include "mnblas.h"

float cblas_sasum(const int n, const float *x, const int incx)
{
    float asum = 0.0;
    register unsigned int i = 0;

    for (; (i < n); i += incx * 4)
    {
        asum += fabsf(x[i]);
        asum += fabsf(x[i + 1*incX]);
        asum += fabsf(x[i + 2*incX]);
        asum += fabsf(x[i + 3*incX]);
    }

    return asum;
}

float cblas_scasum(const int n, const void *x, const int incx)
{
    cplx_t *c = (cplx_t *)(x);
    float asum = 0.0;
    register unsigned int i = 0;

    for (; (i < n); i += incx * 4)
    {
        asum = asum + fabsf(c[i].re) + fabsf(c[i].im);
        asum = asum + fabsf(c[i + 1*incX].re) + fabsf(c[i + 1*incX].im);
        asum = asum + fabsf(c[i + 2*incX].re) + fabsf(c[i + 2*incX].im);
        asum = asum + fabsf(c[i + 3*incX].re) + fabsf(c[i + 3*incX].im);
    }

    return asum;
}

double cblas_dasum(const int n, const double *x, const int incx)
{
    double asum = 0.0;
    register unsigned int i = 0;

    for (; (i < n); i += incx * 4)
    {
        asum += fabs(x[i]);
        asum += fabs(x[i + 1*incX]);
        asum += fabs(x[i + 2*incX]);
        asum += fabs(x[i + 3*incX]);
    }

    return asum;
}

double cblas_dzasum(const int n, const void *x, const int incx)
{
    cplx_t *c = (cplx_t *)(x);
    double asum = 0.0;
    register unsigned int i = 0;

    for (; (i < n); i += incx * 4)
    {
        asum = asum + fabs(c[i].re) + fabs(c[i].im);
        asum = asum + fabs(c[i + 1*incX].re) + fabs(c[i + 1*incX].im);
        asum = asum + fabs(c[i + 2*incX].re) + fabs(c[i + 2*incX].im);
        asum = asum + fabs(c[i + 3*incX].re) + fabs(c[i + 3*incX].im);
    }
    
    return asum;
}