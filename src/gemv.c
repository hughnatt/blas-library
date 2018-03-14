#include "mnblas.h"
#include <stdio.h>
#include <stdlib.h> 

void mncblas_sgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const float alpha, const float *a, const int lda, const float *x, const int incx, 
                 const float beta, float *y, const int incy)
{

<<<<<<< HEAD
=======
    register unsigned int i = 0;
    register unsigned int j = 0;
    float temp;
    float *ligne;
    int cmp = 0,k;

    if(trans==111){
        k=m;
    }
    else{
        k=n;
    }

    for(;i<k;i+=incy){
        if(((Layout == 101)&&(trans==111))||((Layout == 102)&&(trans==112))){
            //RowMajor
            ligne = (float*)(a + cmp);
            cmp+=lda;
        }
        else{
            //ColMajor
            cmp=i;
            ligne = malloc(n*sizeof(float));
            for(j=0;j<m+n-k;j++){
                ligne[j] = a[cmp];
                cmp+=lda;
            }
        }
        temp = mncblas_sdot(k,x,incx,ligne,1);
        temp = temp * alpha;
        y[i]=temp + beta*y[i];
    }
>>>>>>> dev2
}

void mncblas_dgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n,
                 const double alpha, const double *a, const int lda, const double *x, const int incx, 
                 const double beta, double *y, const int incy)
{
<<<<<<< HEAD

=======
    register unsigned int i = 0;
    register unsigned int j = 0;
    double temp;
    double *ligne;
    int cmp = 0,k;

    if(trans==111){
        k=m;
    }
    else{
        k=n;
    }

    for(;i<k;i+=incy){
        if(((Layout == 101)&&(trans==111))||((Layout == 102)&&(trans==112))){
            //RowMajor
            ligne = (double*)(a + cmp);
            cmp+=lda;
        }
        else{
            //ColMajor
            cmp=i;
            ligne = malloc(n*sizeof(double));
            for(j=0;j<m+n-k;j++){
                ligne[j] = a[cmp];
                cmp+=lda;
            }
        }
        temp = mncblas_ddot(k,x,incx,ligne,1);
        temp = temp * alpha;
        y[i]=temp + beta*y[i];
    }
>>>>>>> dev2
}

void mncblas_cgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{
<<<<<<< HEAD

=======

    register unsigned int i = 0;
    register unsigned int j = 0;
    cplx_t *array_a = (cplx_t*)a;
    cplx_t *array_x = (cplx_t*)x;
    cplx_t *array_y = (cplx_t*)y;
    cplx_t temp;
    cplx_t *ligne;
    int cmp = 0,k;

    if(trans==111){
        k=m;
    }
    else{
        k=n;
    }

    for(;i<k;i+=incy){
        if(trans==113){
            if(Layout == 102){
                for(j=0;j<m+n-k;j++){
                    cconj(&array_a[cmp+j],&ligne[j]);
                }
                cmp+=lda;
            }
            else{
                cmp=i;
                ligne = malloc(n*sizeof(cplx_t));
                for(j=0;j<m+n-k;j++){
                    cconj(&array_a[cmp],&ligne[j]);
                    cmp+=lda;
                }
            }
        }
        else if(((Layout == 101)&&(trans==111))||((Layout == 102)&&(trans==112))){
            ligne = (cplx_t*)(array_a + cmp);
            cmp+=lda;
        }
        else{
            cmp=i;
            ligne = malloc(n*sizeof(cplx_t));
            for(j=0;j<m+n-k;j++){
                ligne[j] = array_a[cmp];
                cmp+=lda;
            }
        }
        temp.re = 0.0;
        temp.im = 0.0;
        for(j=0;j<m+n-k;j++){
            temp.re += array_x[j].re*ligne[j].re - array_x[j].im*ligne[j].im;
            temp.im += array_x[j].re*ligne[j].im + array_x[j].im*ligne[j].re;
        }
        temp.re = temp.re * *(float*)alpha;
        temp.im = temp.im * *(float*)alpha;
        array_y[i].re = temp.re + *(float*)beta*array_y[i].re;
        array_y[i].im = temp.im + *(float*)beta*array_y[i].im;
    }
>>>>>>> dev2
}
void mncblas_zgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, 
                 const void *alpha, const void *a, const int lda, const void *x, const int incx, 
                 const void *beta, void *y, const int incy)
{
    register unsigned int i = 0;
    register unsigned int j = 0;
    cplxd_t *array_a = (cplxd_t*)a;
    cplxd_t *array_x = (cplxd_t*)x;
    cplxd_t *array_y = (cplxd_t*)y;
    cplxd_t temp;
    cplxd_t *ligne;
    int cmp = 0,k;

    if(trans==111){
        k=m;
    }
    else{
        k=n;
    }

    for(;i<k;i+=incy){
        if(trans==113){
            if(Layout == 102){
                for(j=0;j<m+n-k;j++){
                    zconj(&array_a[cmp+j],&ligne[j]);
                }
                cmp+=lda;
            }
            else{
                cmp=i;
                ligne = malloc(n*sizeof(cplxd_t));
                for(j=0;j<m+n-k;j++){
                    zconj(&array_a[cmp],&ligne[j]);
                    cmp+=lda;
                }
            }
        }
        else if(((Layout == 101)&&(trans==111))||((Layout == 102)&&(trans==112))){
            ligne = (cplxd_t*)(array_a + cmp);
            cmp+=lda;
        }
        else{
            cmp=i;
            ligne = malloc(n*sizeof(cplxd_t));
            for(j=0;j<m+n-k;j++){
                ligne[j] = array_a[cmp];
                cmp+=lda;
            }
        }
        temp.re = 0.0;
        temp.im = 0.0;
        for(j=0;j<m+n-k;j++){
            temp.re += array_x[j].re*ligne[j].re - array_x[j].im*ligne[j].im;
            temp.im += array_x[j].re*ligne[j].im + array_x[j].im*ligne[j].re;
        }
        temp.re = temp.re * *(double*)alpha;
        temp.im = temp.im * *(double*)alpha;
        array_y[i].re = temp.re + *(double*)beta*array_y[i].re;
        array_y[i].im = temp.im + *(double*)beta*array_y[i].im;
    }
}