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

void cconj(const cplx_t* a, cplx_t* conj){
    conj->re = a->re;
    conj->im = -a->im;
}

void zconj(const cplxd_t* a, cplxd_t* conj){
    conj->re = a->re;
    conj->im = -a->im;
}

// a = a + b
void cadd(cplx_t* a, const cplx_t* b){
    a->re = a->re + b->re;
    a->im = a->im + b->im;
}
// a = a + b
void zadd(cplxd_t* a, const cplxd_t* b){
    a->re = a->re + b->re;
    a->im = a->im + b->im;
}