#include "mnblas.h"

void cmult(const cplx_t* a, const cplx_t* b, cplx_t* result){
    cplx_t result;
    
    result->re = a->re * b->re + a->im * b->im;
    result->im = a->re * b->im + b->re * a->im;
}

void zmult(const cplxd_t* a, const cplxd_t* b, cplxd_t* result){
    cplxd_t result;
    
    result->re = a->re * b->re + a->im * b->im;
    result->im = a->re * b->im + b->re * a->im;

}

cplx_t cconj(const cplx_t a){
    cplx_t cconj;
    cconj.re = a.re;
    cconj.im = -a.im;
    return cconj;
}

cplxd_t zconj(const cplxd_t a){
    cplxd_t zconj;
    zconj.re = a.re;
    zconj.im = -a.im;
    return zconj;
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