# This function sets the value of the passe variable name to 'stdc++' if
# we are using libstc++, and to 'c++' if we are using libc++

function(get_standard_library_name RETURN_VARIABLE_NAME)
   check_cxx_source_compiles("
#include <iostream>

int a =
#ifdef __GLIBCXX__
    1;
#else
    fgsfds;
#endif

int main(int argc, char* argv[])
{
  return 0;
}
"
     HAVE_LIBSTCPP)

  if(HAVE_LIBSTCPP)
    set(${RETURN_VARIABLE_NAME} "stdc++" PARENT_SCOPE)
  else()
    set(${RETURN_VARIABLE_NAME} "c++" PARENT_SCOPE)
  endif()
endfunction()
