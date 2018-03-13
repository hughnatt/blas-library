#include <stdlib.h>

#define VECSIZE 100

typedef struct {
    float re;
    float im;
} Complex_c;

typedef struct {
    float re;
    float im;
} Complex_z;

/*
 * Type vecteur réel simple précision: @vfloat 
 * Type vecteur réel double précision: @vdouble
 * Type vecteur complexe simple précision @vcplx
 * Type vecteur complexe double précision @vcplxd
 */
typedef float vfloat[VECSIZE];
typedef double vdouble[VECSIZE];
typedef Complex_c vcplx[VECSIZE];
typedef Complex_z vcplxd[VECSIZE];

void  vfloat_init(vfloat V, float x);
void vdouble_init(vdouble V, double x);
void   vcplx_init(vcplx V, Complex_c x);
void  vcplxd_init(vcplxd V, Complex_z x);

void  vfloat_rand(vfloat V);
void vdouble_rand(vdouble V);
void   vcplx_rand(vcplx V);
void  vcplxd_rand(vcplxd V);

void  vfloat_print(vfloat V);
void vdouble_print(vdouble V);
void   vcplx_print(vcplx V);
void  vcplxd_print(vcplxd V);

void mn_asum_test_all();
void mn_axpy_test_all();
void mn_copy_test_all();
void  mn_dot_test_all();
void mn_dotu_test_all();
void mn_dotc_test_all();
void mn_gemm_test_all();
void mn_gemv_test_all();
void mn_nrm2_test_all();
void mn_swap_test_all();
