// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

import data;

#include <gtest/gtest.h>

TEST(Database, VerifyBasics) {
  data::Database database;
  database.query("CREATE TABLE integers (i INTEGER, j INTEGER)");
  database.query("INSERT INTO integers VALUES (3, 4), (5, 6), (7, NULL)");
  database.print("SELECT * FROM integers");
  auto res = database.query("SELECT * FROM integers");
  EXPECT_EQ(res.rowCount(), 3);
  EXPECT_EQ(res.columnCount(), 2);
  auto names = res.names();
  EXPECT_EQ(names.size(), 2);
  EXPECT_EQ(names[0], "i");
  EXPECT_EQ(names[1], "j");
}

TEST(Database, VerifyValues) {
  data::Database database;
  database.query("CREATE TABLE integers (i INTEGER, j INTEGER)");
  database.query("INSERT INTO integers VALUES (3, 4), (5, 6), (7, NULL)");
  database.print("SELECT * FROM integers");
  auto res = database.query("SELECT * FROM integers");
  EXPECT_EQ(res.rowCount(), 3);
  EXPECT_EQ(res.columnCount(), 2);

  EXPECT_EQ(res.chunk(), 3);
}
