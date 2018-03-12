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

cplx_t conj(cplx_t* a){
    cplx_t result;

    result.re = a->re;
    result.im = -a->im;

    return result;
}


cplxd_t conjd(cplxd_t* a){
    cplxd_t result;

    result.re = a->re;
    result.im = -a->im;

    return result;
}

// a = a + b
void add(cplx_t* a, cplx_t* b){
    a->re = a->re + b->re;
    a->im = a->im + b->im;
}
// a = a + b
void addd(cplxd_t* a, cplxd_t* b){
    a->re = a->re + b->re;
    a->im = a->im + b->im;
}