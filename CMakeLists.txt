# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.29)

project(angohr
  VERSION 0.0.1
  DESCRIPTION "A revolutionary new thing I am working on"
  HOMEPAGE_URL "https://cryos.net/"
  LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH "${angohr_SOURCE_DIR}/cmake")
include(utils)

add_subdirectory(angohr)

option(BUILD_TESTS "Build tests for the project" ON)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
