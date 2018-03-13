#include <stdlib.h>
#include <maths.h>
#include "mnblas.h"

float cblas_sasum(const int n, const float *x, const int incx)
{
    float asum = 0.0;
    register unsigned int i = 0;

    if (n % 4 == 0)
    {
        for (; (i < n); i += incx * 4)
        {
            asum += fabsf(x[i]);
            asum += fabsf(x[i + 1]);
            asum += fabsf(x[i + 2]);
            asum += fabsf(x[i + 3]);
        }
    }
    else
    {
        for (; (i < n); i += incx)
        {
            asum += fabsf(x[i]);
        }
    }
    return asum;
}

float cblas_scasum(const int n, const void *x, const int incx)
{
    cplx_t *c = (cplx_t *)(x);
    float asum = 0.0;
    register unsigned int i = 0;

    if (n % 4 == 0)
    {
        for (; (i < n); i += incx*4)
        {
            asum = asum + fabsf(c[i].re) + fabsf(c[i].im);
            asum = asum + fabsf(c[i+1].re) + fabsf(c[i+1].im);
            asum = asum + fabsf(c[i+2].re) + fabsf(c[i+2].im);
            asum = asum + fabsf(c[i+3].re) + fabsf(c[i+3].im);            
        }
    }
    else
    {
        for (; (i < n); i += incx)
        {
            asum = asum + fabsf(c[i].re) + fabsf(c[i].im);
        }
    }
    return asum;
}

double cblas_dasum(const int n, const double *x, const int incx)
{
    double asum = 0.0;
    register unsigned int i = 0;
    
    if (n % 4 == 0)
    {
        for (; (i < n); i += incx * 4)
        {
            asum += fabs(x[i]);
            asum += fabs(x[i + 1]);
            asum += fabs(x[i + 2]);
            asum += fabs(x[i + 3]);
        }
    }
    else
    {
        for (; (i < n); i += incx)
        {
            asum += fabs(x[i]);
        }
    }
    return asum;
}

double cblas_dzasum(const int n, const void *x, const int incx)
{
    cplx_t *c = (cplx_t *)(x);
    double asum = 0.0;
    register unsigned int i = 0;

    if (n % 4 == 0)
    {
        for (; (i < n); i += incx*4)
        {
            asum = asum + fabs(c[i].re) + fabs(c[i].im);
            asum = asum + fabs(c[i+1].re) + fabs(c[i+1].im);
            asum = asum + fabs(c[i+2].re) + fabs(c[i+2].im);
            asum = asum + fabs(c[i+3].re) + fabs(c[i+3].im);            
        }
    }
    else
    {
        for (; (i < n); i += incx)
        {
            asum = asum + fabs(c[i].re) + fabs(c[i].im);
        }
    }
    return asum;
}