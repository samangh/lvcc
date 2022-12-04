#include "globals.h"


#ifdef __cplusplus
extern "C" {
#endif
#include <lv_prolog.h>

typedef struct {
    int32_t dimSize;
    int32_t elt[1];
} arr1D_int32;
typedef arr1D_int32** arr1DH_int32;

typedef struct {
    int32_t dimSize;
    double elt[1];
} arr1D_double;
typedef arr1D_double** arr1DH_double;


#include <lv_epilog.h>
#ifdef __cplusplus
}
#endif
