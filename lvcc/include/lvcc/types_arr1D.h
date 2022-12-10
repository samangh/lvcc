#pragma once

#include <extcode.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <lv_prolog.h>

typedef struct {
    int8_t dimSize;
    int8 elt[1];
} arr1D_int8;
typedef arr1D_int8** arr1DH_int8;

typedef struct {
    int16_t dimSize;
    int16 elt[1];
} arr1D_int16;
typedef arr1D_int16** arr1DH_int16;

typedef struct {
    int32_t dimSize;
    int32 elt[1];
} arr1D_int32;
typedef arr1D_int32** arr1DH_int32;

typedef struct {
    int32_t dimSize;
    int64 elt[1];
} arr1D_int64;
typedef arr1D_int64** arr1DH_int64;

typedef struct {
    int32_t dimSize;
    uInt8 elt[1];
} arr1D_uint8;
typedef arr1D_uint8** arr1DH_uint8;

typedef struct {
    int32_t dimSize;
    uInt16 elt[1];
} arr1D_uint16;
typedef arr1D_uint16** arr1DH_uint16;

typedef struct {
    int32_t dimSize;
    uInt32 elt[1];
} arr1D_uint32;
typedef arr1D_uint32** arr1DH_uint32;

typedef struct {
    int32_t dimSize;
    uInt64 elt[1];
} arr1D_uint64;
typedef arr1D_uint64** arr1DH_uint64;

typedef struct {
    int32_t dimSize;
    double elt[1];
} arr1D_double;
typedef arr1D_double** arr1DH_double;

typedef struct {
    int32_t dimSize;
    LVBoolean elt[1];
} arr1D_bool, **arr1DH_bool;

#include <lv_epilog.h>
#ifdef __cplusplus
}
#endif
