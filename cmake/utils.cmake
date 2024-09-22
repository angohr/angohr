# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

function(angohr_target_properties TARGET)
  set_target_properties(${TARGET}
    PROPERTIES
      CXX_STANDARD 20
      CXX_STANDARD_REQUIRED ON
      CXX_EXTENSIONS OFF
      COMPILE_WARNING_AS_ERROR ON)
endfunction()
