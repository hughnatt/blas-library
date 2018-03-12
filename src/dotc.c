#include "mnblas.h"

void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  register unsigned int i = 0;
  register unsigned int j = 0;

  dotc = (cplx_t*) dotc;
  cplx_t** array_x = (cplx_t**) X;
  cplx_t** array_y = (cplx_t**) Y;


  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cplx_t temp = mult(conj(array_x[i]),array_y[j]);
    add(dotc,&temp);
  }
}

void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  register unsigned int i = 0;
  register unsigned int j = 0;

  dotc = (cplxd_t*) dotc;
  cplxd_t** array_x = (cplxd_t**) X;
  cplxd_t** array_y = (cplxd_t**) Y;


  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cplxd_t temp = multd(conjd(array_x[i]),array_y[j]);
    addd(dotc,&temp);
  }
}