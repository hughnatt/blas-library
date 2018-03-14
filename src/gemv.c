#include "mnblas.h"

void cblas_sgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const float alpha, const float *a, const int lda, const float *x, const int incx, 
                 const float beta, float *y, const int incy)
{

}

void cblas_dgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n,
                 const double alpha, const double *a, const int lda, const double *x, const int incx, 
                 const double beta, double *y, const int incy)
{

}

void cblas_cgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{

}
void cblas_zgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{
    /* a completer */
}
