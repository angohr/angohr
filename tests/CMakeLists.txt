# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

find_package(GTest CONFIG REQUIRED)

add_executable(angohr-test angohr-test.cpp database-test.cpp)
target_link_libraries(angohr-test PRIVATE GTest::gtest GTest::gtest_main angohr::core angohr::data)
angohr_target_properties(angohr-test)

#add_test(angohr-tests angohr-test)

include(GoogleTest)
gtest_discover_tests(angohr-test)
