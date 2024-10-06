# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

function(angohr_target_properties TARGET)
  # Configure some simple arguments for the function.
  set(options IMPORT_STD CXX23)
  cmake_parse_arguments(_args "${options}" "" "" ${ARGN})

  target_compile_options(${TARGET} PRIVATE -Wall -Wextra)

  if(_args_IMPORT_STD)
    message(STATUS "${TARGET} is a C++ STD Module target")
    target_compile_features(${TARGET}
      PRIVATE   cxx_std_23
      INTERFACE cxx_std_23)
    set_target_properties(${TARGET}
      PROPERTIES
        CXX_MODULE_STD ON)
  else()
    message(STATUS "${TARGET} is a C++20 target")
    set_target_properties(${TARGET}
      PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        COMPILE_WARNING_AS_ERROR ON)
  endif()
  if(_args_CXX23)
    message(STATUS "${TARGET} is a C++23 target")
    set_target_properties(${TARGET}
      PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        COMPILE_WARNING_AS_ERROR ON)
  endif()
endfunction()
