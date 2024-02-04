find_package(fmt CONFIG REQUIRED)

add_library(core)
target_sources(core
  PUBLIC
    FILE_SET CXX_MODULES FILES
      core.cpp
      ello.cpp)
target_link_libraries(core PRIVATE fmt::fmt)
add_library(angohr::core ALIAS core)

add_executable(angohr angohr.cpp)

set_target_properties(core
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNINGS_AS_ERRORS ON)
set_target_properties(angohr
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNINGS_AS_ERRORS ON)

target_link_libraries(angohr PRIVATE core)
