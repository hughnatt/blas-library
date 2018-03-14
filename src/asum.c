/*
 * RICM3 - Méthodes Numériques - 2018
 * ANCRENAZ Ariane - SAUTON Tanguy
 * C Implementation of BLAS routines
 */

#include "mnblas.h"
#include <stdlib.h>
#include <math.h>


/*
 * cblas_?asum
 * Computes the sum of magnitudes of the vector elements.
 * res = |Re x1| + |Im x1| + |Re x2| + |Im x2| + ... + |Re xn| + |Im xn| 
 * 
 * Types : s / sc / d / dz
 */

float mncblas_sasum(const int n, const float *x, const int incX)
{
    float asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        asum += fabsf(x[i]);
<<<<<<< HEAD
        asum += fabsf(x[i + incX]);
        asum += fabsf(x[i + 2 * incX]);
        asum += fabsf(x[i + 3 * incX]);
=======
        asum += fabsf(x[i + 1*incX]);
        asum += fabsf(x[i + 2*incX]);
        asum += fabsf(x[i + 3*incX]);
>>>>>>> dev2
    }

    return asum;
}

float mncblas_scasum(const int n, const void *x, const int incX)
{
    cplx_t *c = (cplx_t *)(x);
    float asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        asum = asum + fabsf(c[i].re) + fabsf(c[i].im);
<<<<<<< HEAD
        asum = asum + fabsf(c[i + incX].re) + fabsf(c[i + incX].im);
        asum = asum + fabsf(c[i + 2 * incX].re) + fabsf(c[i + 2 * incX].im);
        asum = asum + fabsf(c[i + 3 * incX].re) + fabsf(c[i + 3 * incX].im);
=======
        asum = asum + fabsf(c[i + 1*incX].re) + fabsf(c[i + 1*incX].im);
        asum = asum + fabsf(c[i + 2*incX].re) + fabsf(c[i + 2*incX].im);
        asum = asum + fabsf(c[i + 3*incX].re) + fabsf(c[i + 3*incX].im);
>>>>>>> dev2
    }

    return asum;
}

double mncblas_dasum(const int n, const double *x, const int incX)
{
    double asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        asum += fabs(x[i]);
<<<<<<< HEAD
        asum += fabs(x[i + incX]);
        asum += fabs(x[i + 2 * incX]);
        asum += fabs(x[i + 3 * incX]);
=======
        asum += fabs(x[i + 1*incX]);
        asum += fabs(x[i + 2*incX]);
        asum += fabs(x[i + 3*incX]);
>>>>>>> dev2
    }

    return asum;
}

double mncblas_dzasum(const int n, const void *x, const int incX)
{
    cplx_t *c = (cplx_t *)(x);
    double asum = 0.0;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
<<<<<<< HEAD
        asum += fabs(c[i].re) + fabs(c[i].im);
        asum += fabs(c[i + incX].re) + fabs(c[i + incX].im);
        asum += fabs(c[i + 2 * incX].re) + fabs(c[i + 2 * incX].im);
        asum += fabs(c[i + 3 * incX].re) + fabs(c[i + 3 * incX].im);
=======
        asum = asum + fabs(c[i].re) + fabs(c[i].im);
        asum = asum + fabs(c[i + 1*incX].re) + fabs(c[i + 1*incX].im);
        asum = asum + fabs(c[i + 2*incX].re) + fabs(c[i + 2*incX].im);
        asum = asum + fabs(c[i + 3*incX].re) + fabs(c[i + 3*incX].im);
>>>>>>> dev2
    }
}

