#pragma once

#include <extcode.h>

#define GEN_1D_ARRAY(T)         \
    typedef struct {            \
        int32_t dimSize;        \
        T elt[1];               \
    } arr1D_##T;                \
    typedef arr1D_##T** arr1DH_##T;

#define GEN_nD_ARRAY(N,T)       \
    typedef struct {            \
        int32_t dimSize[N];     \
        T elt[1];               \
    } arr_##N##T;               \

#define GEN_ARRAY(T)            \
    GEN_1D_ARRAY(T)             \
    GEN_nD_ARRAY(2,T)           \
    GEN_nD_ARRAY(3,T)           \
    GEN_nD_ARRAY(4,T)           \

#ifdef __cplusplus
extern "C" {
#endif
#include <lv_prolog.h>

GEN_1D_ARRAY(int8)
GEN_1D_ARRAY(int16)
GEN_1D_ARRAY(int32)
GEN_1D_ARRAY(int64)

GEN_1D_ARRAY(uInt8)
GEN_1D_ARRAY(uInt16)
GEN_1D_ARRAY(uInt32)
GEN_1D_ARRAY(uInt64)

GEN_1D_ARRAY(double)
GEN_1D_ARRAY(bool)

#include <lv_epilog.h>
#ifdef __cplusplus
}
#endif
