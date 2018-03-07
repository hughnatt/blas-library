#include "mnblas.h"
#include "math.h"

float cblas_snrm2(const int n, const float *x, const int incx){
    register unsigned int i = 0 ;
    float nrm;

    for (; (i < n) ; i += incx){
        nrm += x[i]*x[i];
    }
    return sqrt(nrm);
}

double cblas_dnrm2(const int n, const double *x, const int incx);

float cblas_scnrm2(const int n, const void *x, const int incx);

double cblas_dznrm2(const int n, const void *x, const int incx);
