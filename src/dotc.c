#include "mnblas.h"

void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  dotc = (cplx_t *) dotc;
  cplx_t* array_x = (cplx_t *) X;
  cplx_t* array_y = (cplx_t *) Y;

  cplx_t conjx;
  cplx_t mult;

  register unsigned int i = 0;
  register unsigned int j = 0;
  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    cconj(&array_x[i],&conjx);
    cmult(&conjx, &array_y[j], &mult);
    cadd(dotc, &mult);
  }
}

void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  dotc = (cplxd_t *) dotc;
  cplxd_t* array_x = (cplxd_t *) X;
  cplxd_t* array_y = (cplxd_t *) Y;

  cplxd_t conjx;
  cplxd_t mult;

  register unsigned int i = 0;
  register unsigned int j = 0;
  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    zconj(&array_x[i],&conjx);
    zmult(&conjx, &array_y[j], &mult);
    zadd(dotc, &mult);
  }
}