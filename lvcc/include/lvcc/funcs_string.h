#pragma once

#include <extcode.h>

#include <cstring>
#include <algorithm>

namespace lvcc {

void PopulateStringHandle(MgErr& err, LStrHandle* strHandle, const std::string& text)
{

    auto new_length = text.size()+1;
    auto old_length = (*strHandle != nullptr) ? (**strHandle)->cnt : 1;

    err = NumericArrayResize(uB, old_length, (UHandle*)strHandle, new_length);
    if (err != noErr)
        return;

    //Empties the buffer, as NumericArrayResize does not
    memset(LStrBuf(**strHandle), '\0', new_length);

    //Fills the string buffer with stringData
    std::copy_n(text.c_str(), new_length, (char*)LStrBuf(**strHandle));

    //Informs the LabVIEW string handle about the size of the size
    LStrLen(**strHandle) = new_length;
}

LStrHandle CreateStringHandle(MgErr& err, const std::string& text)
{
    /* Create minimal LStrHandle */
    auto newStringHandle = (LStrHandle)DSNewHandle(sizeof(LStr));
    LStrLen(*newStringHandle) = 1;

    PopulateStringHandle(err, &newStringHandle, text);
    return newStringHandle;
}

}
