# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.30)

# The vcpkg manifest features need to be before the project call.
option(BUILD_TESTS "Build tests for the project" OFF)
if(BUILD_TESTS)
  list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif()

project(angohr
  VERSION 0.0.1
  DESCRIPTION "A revolutionary new thing I am working on"
  HOMEPAGE_URL "https://cryos.net/"
  LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH "${angohr_SOURCE_DIR}/cmake")
include(utils)

add_subdirectory(angohr)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
