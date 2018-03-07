#include <stdio.h>
#include <cblas.h>

#include "mnblas.h"

/*
  Mesure des cycles
*/

#include <x86intrin.h>


#define VECSIZE    1000

typedef float vfloat [VECSIZE] ;

vfloat vec1, vec2 ;

void vector_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vector_print (vfloat V)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    printf ("%f ", V[i]) ;
  printf ("\n") ;
  
  return ;
}

int main (int argc, char **argv)
{
 unsigned long long start, end ;
 unsigned long long residu ;

 /* Calcul du residu de la mesure */
  start = _rdtsc () ;
  end = _rdtsc () ;
  residu = end - start ;
  
  vector_init (vec1, 1.0) ;

  start = _rdtsc () ;
     cblas_scopy (VECSIZE, vec1, 1, vec2, 1) ;
  end = _rdtsc () ;

  printf ("cblas_scopy1 nombre de cycles cblas: %Ld \n", end-start-residu) ;


  
  start = _rdtsc () ;
     mncblas_scopy (VECSIZE, vec1, 1, vec2, 1) ;
  end = _rdtsc () ;

  /*
  printf ("Vector 2:\n") ;
  vector_print (vec2) ;
  */
  
  printf ("mncblas_scopy: nombre de cycles: %Ld \n", end-start-residu) ;

  start = _rdtsc () ;
     cblas_scopy (VECSIZE, vec1, 1, vec2, 1) ;
  end = _rdtsc () ;

  printf ("cblas_scopy2 nombre de cycles cblas: %Ld \n", end-start-residu) ;

  
}
