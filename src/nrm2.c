#include "mnblas.h"
#include "math.h"

float cblas_snrm2(const int n, const float *x, const int incX)
{
    float nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        nrm += x[i] * x[i];
        nrm += x[i + 1*incX] * x[i + 1*incX];
        nrm += x[i + 2*incX] * x[i + 2*incX];
        nrm += x[i + 3*incX] * x[i + 3*incX];
    }

    return sqrtf(nrm);
}

double cblas_dnrm2(const int n, const double *x, const int incX)
{
    double nrm;

    register unsigned int i = 0;
    for (; (i < n); i += incX * 4)
    {
        nrm += x[i] * x[i];
        nrm += x[i + 1*incX] * x[i + 1*incX];
        nrm += x[i + 2*incX] * x[i + 2*incX];
        nrm += x[i + 3*incX] * x[i + 3*incX];
    }

    return sqrt(nrm);
}

float cblas_scnrm2(const int n, const void *x, const int incX)
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

double cblas_dznrm2(const int n, const void *x, const int incX)
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
