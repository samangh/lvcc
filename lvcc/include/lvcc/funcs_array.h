#include "types_arr1D.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

namespace lvcc {

void ResizeArray(MgErr& err, NumType element_type, int32 dimension, UHandle* handle_ptr, size_t no_elements)
{
    err = NumericArrayResizeNoInit(element_type, dimension, handle_ptr, no_elements);
    //NumericArrayResize for some reasonreturns non-sensial error messages, ignore
    if(err<0 || err>=2048)
        err=mgNoErr;

    if(err!=mgNoErr)
        return;

    // Cast to smallest possible array handle, and set the array sie
    // This works becasue the first element of the array structs is dimSize
    auto a = (arr1DH_bool*)(handle_ptr);
    (**a)->dimSize=no_elements;
}

arr1DH_int32 create_arr1DH_int32(MgErr& err, size_t array_length)
{
    auto handle = (arr1DH_int32)DSNewHandle(sizeof(arr1D_int32));

    err = NumericArrayResize(iL, 1, (UHandle*)&handle, array_length);
    if (err != noErr)
        return handle;

    (*handle)->dimSize = array_length;
    return handle;
}

}
