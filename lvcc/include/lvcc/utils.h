#include "globals.h"
#include "types.h"

#include <string>
#include <algorithm>
#include <vector>

MgErr PopulateStringHandle(LStrHandle* strHandle, const std::string& text)
{

    auto new_length = text.size()+1;
    auto old_length = (*strHandle != nullptr) ? (**strHandle)->cnt : 1;

    auto err = NumericArrayResize(uB, old_length, (UHandle*)strHandle, new_length);
    if (err != noErr)
        return err;

    //Empties the buffer, as NumericArrayResize does not
    memset(LStrBuf(**strHandle), '\0', new_length);

    //Fills the string buffer with stringData
    std::copy_n(text.c_str(), new_length, (char*)LStrBuf(**strHandle));

    //Informs the LabVIEW string handle about the size of the size
    LStrLen(**strHandle) = new_length;

    return noErr;
}

LStrHandle CreateStringHandle(const std::string& text, MgErr& err)
{
    /* Create minimal LStrHandle */
    auto newStringHandle = (LStrHandle)DSNewHandle(sizeof(LStr));
    LStrLen(*newStringHandle) = 1;

    err = PopulateStringHandle(&newStringHandle, text);
    return newStringHandle;
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

arr1DH_double create_arr1DH_double(MgErr& err, size_t array_length)
{
    auto handle = (arr1DH_double)DSNewHandle(sizeof(arr1D_double));

    err = NumericArrayResize(fD, 1, (UHandle*)&handle, array_length);
    if (err != noErr)
        return handle;

    (*handle)->dimSize = array_length;
    return handle;
}

arr1DH_double create_arr1DH_double(MgErr& err, std::vector<double> data)
{
    auto handle = create_arr1DH_double(err, data.size());
    if (err !=0)
        return handle;

    for(int i=0; i < (**handle).dimSize; i++)
        (**handle).elt[i]=data[i];

    return handle;
}

void populate_arr1DH_double(MgErr& err, arr1DH_double handle, std::vector<double> data)
{
    err = NumericArrayResize(fD, (*handle)->dimSize, (UHandle*)&handle, data.size());
    if (err != noErr)
        return;

    (*handle)->dimSize = data.size();

    for(int i=0; i < (*handle)->dimSize; i++)
        (**handle).elt[i]=data[i];
}

