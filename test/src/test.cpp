#include <lvcc/lvcc.h>
#include "lvcc/export/test.h"

extern "C" TEST_EXPORT int32_t multiply(int32 a, int32 b)
{
    return a*b;
}

extern "C" TEST_EXPORT void multiply_arr(arr1DH_int32 arr, int32_t a)
{
    for (int i=0; i<(**arr).dimSize; ++i)
        (*arr)->elt[i]=(**arr).elt[i]*a;
}

extern "C" TEST_EXPORT MgErr resize_array(arr1DH_int32 arr, int32_t new_size)
{    
   MgErr err;
   lvcc::ResizeArray(err, fD, 1, (UHandle*)&arr, new_size);

   return err;
}
