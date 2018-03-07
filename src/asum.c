#include <stdlib.h>
#include "mnblas.h"

float cblas_sasum (const int n, const float *x, const int incx){
    
    register unsigned int i = 0 ;
    float asum;

    for (; (i < n) ; i += incx){
        asum += abs(x[i]);
    }
    return asum;
}

float cblas_scasum (const int n, const void *x, const int incx){

}

double cblas_dasum (const int n, const double *x, const int incx){

}

double cblas_dzasum (const int n, const void *x, const int incx){
    
}