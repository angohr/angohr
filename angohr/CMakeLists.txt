# SPDX-FileCopyrightText: Copyright contributors to the Angohr project
# SPDX-License-Identifier: BSD-3-Clause

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(DuckDB CONFIG REQUIRED)
# This is just for DuckDB...their config file doesn't find Threads.
find_package(Threads REQUIRED)

add_library(core)
target_sources(core
  PUBLIC
    FILE_SET CXX_MODULES FILES
      array.cpp
      core.cpp
      database.cpp
      ello.cpp)
target_link_libraries(core PRIVATE fmt::fmt spdlog::spdlog duckdb)
add_library(angohr::core ALIAS core)

add_executable(angohr angohr.cpp)

angohr_target_properties(core)
angohr_target_properties(angohr)

target_link_libraries(angohr PRIVATE core)
