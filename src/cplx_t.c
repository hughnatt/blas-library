#include "mnblas.h"

cplx_t mult(cplx_t* a, cplx_t* b){
    cplx_t result;
    
    result.re = a->re * b->re + a->im * b->im;
    result.im = a->re * b->im + b->re * a->im;

    return result;
}

cplxd_t multd(cplxd_t* a, cplxd_t* b){
    cplxd_t result;
    
    result.re = a->re * b->re + a->im * b->im;
    result.im = a->re * b->im + b->re * a->im;

    return result;
}