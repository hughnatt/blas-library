#include "mnblas.h"

void cblas_saxpy(const int n, const float a, const float *x, const int incx, float *y, const int incy){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < n) && (j < n)) ; i += incx, j += incy)
    {
      y[j] = a * x[i] + y[i] ;
    }
}

void cblas_daxpy(const int n, const double a, const double *x, const int incx, double *y, const int incy){

}

void cblas_caxpy(const int n, const void *a, const void *x, const int incx, void *y, const int incy){

}

void cblas_zaxpy(const int n, const void *a, const void *x, const int incx, void *y, const int incy){

}