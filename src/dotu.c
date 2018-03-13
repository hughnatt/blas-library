/*
 * RICM3 - Méthodes Numériques - 2018
 * ANCRENAZ Ariane - SAUTON Tanguy
 * C Implementation of BLAS routines
 */

#include "mnblas.h"

/*
 * cblas_?dotu
 * Computes a vector-vector dot product
 * res = SUM(i from 1 to n){ Xi * Yi}
 * 
 * Types : c / z
 */ 

void   mncblas_cdotu_sub(const int N, const void* X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  dotu = (cplx_t*) dotu;
  cplx_t* array_x = (cplx_t*) X;
  cplx_t* array_y = (cplx_t*) Y;
  cplx_t mult;

  register unsigned int i = 0;
  register unsigned int j = 0;
  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cmult(&array_x[i],&array_y[j], &mult);
    cadd(dotu,&mult);
  }
}

void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  dotu = (cplxd_t*) dotu;
  cplxd_t* array_x = (cplxd_t*) X;
  cplxd_t* array_y = (cplxd_t*) Y;
  cplxd_t mult;

  register unsigned int i = 0;
  register unsigned int j = 0;
  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    zmult(&array_x[i],&array_y[j], &mult);
    zadd(dotu,&mult);
  }
}