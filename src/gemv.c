#include "mnblas.h"

void cblas_sgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const float alpha, const float *a, const int lda, const float *x, const int incx, 
                 const float beta, float *y, const int incy)
{
    if(trans==111){
        //y = alpha*A*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        float temp;
        float *ligne;
        for(;i<m;i+=incy){
            ligne = a[i];
            temp = mncblas_sdot(n,x,incx,ligne,lda);
            temp = temp * alpha;
            y[i]=temp + beta*y[i];
        }
    }
    else {
        //y = alpha*A'*x + beta*y
        //y = alpha*conjg(A)*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        float temp;
        for(;i<n;i+=incy){
            temp = 0.0;
            for(j=0;j<m;j+=incx){
                temp+=a[j][i]*x[j];
            }
            temp = temp * alpha;
            y[i]=temp + beta*y[i];
        }
    }
}

void cblas_dgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n,
                 const double alpha, const double *a, const int lda, const double *x, const int incx, 
                 const double beta, double *y, const int incy)
{
    if(trans==111){
        //y = alpha*A*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        double temp;
        double *ligne;
        for(;i<m;i+=incy){
            ligne = a[i];
            temp = mncblas_ddot(n,x,incx,ligne,lda);
            temp = temp * alpha;
            y[i]=temp + beta*y[i];
        }
    }
    else {
        //y = alpha*A'*x + beta*y
        //y = alpha*conjg(A)*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        float temp;
        for(;i<n;i+=incy){
            temp = 0.0;
            for(j=0;j<m;j+=incx){
                temp+=a[j][i]*x[j];
            }
            temp = temp * alpha;
            y[i]=temp + beta*y[i];
        }
    }
}

void cblas_cgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{
    if(trans==111){
        //y = alpha*A*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        cplx_t *array_x = (cplx_t*) x;
        cplx_t *array_y = (cplx_t*) y;
        cplx_t *a_cplx = (cplx_t*) a;
        cplx_t temp;
        cplc_t res;
        for(;i<m;i+=incy){
            temp.re = 0.0;
            temp.im = 0.0;
            for(j=0;j<n;j+=incx){
                cmult(a[i][j],x[i],res);
                cadd(temp,res);
            }
            temp = temp * alpha;

            y[i]=temp + beta*y[i];
        }
    }
    else if(trans==112{
        //y = alpha*A'*x + beta*y
        register unsigned int i = 0;
        register unsigned int j = 0;
        float temp;
        for(;i<n;i+=incy){
            temp = 0.0;
            for(j=0;j<m;j+=incx){
                temp+=a[j][i]*x[j];
            }
            temp = temp * alpha;
            y[i]=temp + beta*y[i];
        }
    }
    else{
        //y = alpha*conjg(A)*x + beta*y
    }
}
void cblas_zgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{
    /* a completer */
}
