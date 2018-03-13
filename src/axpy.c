#include "mnblas.h"

void mncblas_saxpy(const int n, const float a, const float *x, const int incx, float *y, const int incy){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < n) && (j < n)) ; i += incx, j += incy)
    {
      y[j] = a * x[i] + y[i] ;
    }
}

void mncblas_daxpy(const int n, const double a, const double *x, const int incx, double *y, const int incy){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < n) && (j < n)) ; i += incx, j += incy)
    {
      y[j] = a * x[i] + y[i] ;
    }
}

void mncblas_caxpy(const int n, const void *a, const void *x, const int incx, void *y, const int incy){
    
    cplx_t* array_x = (cplx_t*) x;
    cplx_t* array_y = (cplx_t*) y;
    cplx_t* scalar_a = (cplx_t*) a;

    cplx_t mult;

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < n) && (j < n)) ; i += incx, j += incy)
    {
        cmult(scalar_a,&array_x[i],&mult);
        cadd(&array_y[j],&mult);
    }
}

void mncblas_zaxpy(const int n, const void *a, const void *x, const int incx, void *y, const int incy){
    
    cplxd_t* array_x = (cplxd_t*) x;
    cplxd_t* array_y = (cplxd_t*) y;
    cplxd_t* scalar_a = (cplxd_t*)  a;
    
    cplxd_t mult;

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    for (; ((i < n) && (j < n)) ; i += incx, j += incy)
    {
        zmult(scalar_a,&array_x[i],&mult);
        zadd(&array_y[j],&mult); 
    }
}