// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

import core;

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Hello, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


TEST(Hello, ModuleImport) {
  core::ello hello;
  hello.hello();
  hello.logSomething();
  EXPECT_EQ(hello.theAnswer(), 42);
}

TEST(Array, RefCount) {
  core::Array<int> array;
  EXPECT_EQ(array.ref(), 1);
}

TEST(Array, Empty) {
  core::Array<int> array;
  EXPECT_EQ(array.empty(), true);
  EXPECT_EQ(array.size(), 0);
}

TEST(Array, Count) {
  core::Array<int> array;
  array.push_back(5);
  EXPECT_EQ(array.empty(), false);
  EXPECT_EQ(array.size(), 1);
  EXPECT_EQ(array.back(), 5);
}

TEST(Array, PushBack) {
  core::Array<int> array;
  array.push_back(7);
  array.push_back(42);
  array.push_back(69);
  EXPECT_EQ(array.empty(), false);
  EXPECT_EQ(array.size(), 3);
  EXPECT_EQ(array.front(), 7);
  EXPECT_EQ(array.at(0), 7);
  EXPECT_EQ(array.at(1), 42);
  EXPECT_EQ(array.at(2), 69);
  EXPECT_EQ(array.back(), 69);
}
