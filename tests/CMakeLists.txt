find_package(GTest CONFIG REQUIRED)

add_executable(angohr-test angohr-test.cpp)
target_link_libraries(angohr-test PRIVATE GTest::gtest GTest::gtest_main angohr::core)
set_target_properties(angohr-test
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNINGS_AS_ERRORS ON)

#add_test(angohr-tests angohr-test)

include(GoogleTest)
gtest_discover_tests(angohr-test)
