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

double cblas_dnrm2(const int n, const double *x, const int incx){
    register unsigned int i = 0 ;
    double nrm;

    for (; (i < n) ; i += incx){
        nrm += x[i]*x[i];
    }
    return sqrt(nrm);
}

float cblas_scnrm2(const int n, const void *x, const int incx){

    cplx_t** array_x = (cplx_t**) x;

    register unsigned int i = 0 ;
    float nrm;
    float cplx_nrm;
    for (; (i < n) ; i += incx){
        cplx_nrm = sqrt(powf(array_x[i]->re,2.0) + powf(array_x[i]->im,2.0));
        nrm += powf(cplx_nrm,2.0);
    }

    return sqrt(nrm);

}

double cblas_dznrm2(const int n, const void *x, const int incx){
    cplxd_t** array_x = (cplxd_t**) x;

    register unsigned int i = 0 ;
    double nrm;
    double cplx_nrm;
    for (; (i < n) ; i += incx){
        cplx_nrm = sqrt(pow(array_x[i]->re,2.0) + pow(array_x[i]->im,2.0));
        nrm += pow(cplx_nrm,2.0);
    }

    return sqrt(nrm);
}
