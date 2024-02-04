import core;

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


TEST(HelloTest, ModuleImport) {
  core::ello hello;
  hello.hello();
  hello.logSomething();
  EXPECT_EQ(hello.theAnswer(), 42);
}
