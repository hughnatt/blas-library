#include "mnblas.h"


void   mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  register unsigned int i = 0;
  register unsigned int j = 0;

  dotu = (cplx_t*) dotu;
  cplx_t** array_x = (cplx_t**) X;
  cplx_t** array_y = (cplx_t**) Y;


  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cplx_t tmp = mult(array_x[i],array_y[j]);
    add(dotu,&tmp);
  }
}

void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  register unsigned int i = 0;
  register unsigned int j = 0;

  dotu = (cplxd_t*) dotu;
  cplxd_t** array_x = (cplxd_t**) X;
  cplxd_t** array_y = (cplxd_t**) Y;


  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cplxd_t tmp = multd(array_x[i],array_y[j]);
    addd(dotu,&tmp);
  }
}