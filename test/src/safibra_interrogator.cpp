#include <lvcc/lvcc.h>
#include "lvcc/export/test.h"

extern "C" TEST_EXPORT arr1DH_int32 tester(MgErr& err)
{    
    auto arr= create_arr1DH_int32(err,10);
    for (int i=0; i<10; ++i)
        (**arr).elt[i]=i;
    return arr;
}
