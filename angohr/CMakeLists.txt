add_library(core)
target_sources(core
  PUBLIC
    FILE_SET CXX_MODULES FILES
      core.cpp)

add_executable(angohr angohr.cpp)

set_target_properties(core
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNINGS_AS_ERRORS ON)
set_target_properties(angohr
    PROPERTIES
      CXX_STANDARD 20
      CXX_STANDARD_REQUIRED ON
      CXX_EXTENSIONS OFF
      COMPILE_WARNINGS_AS_ERRORS ON)
target_link_libraries(angohr PRIVATE core)
#target_compile_features(angohr PUBLIC cxx_std_20)

