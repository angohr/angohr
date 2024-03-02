// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

module;

#include <duckdb.hpp>
#include <fmt/core.h>

export module core : iface.database;

namespace core {

export class QueryResult
{
public:
  QueryResult(std::unique_ptr<duckdb::MaterializedQueryResult> result) {
    m_result = std::move(result);
  }
  int rowCount() {
    if (m_result)
      return m_result->RowCount();
    return -1;
  }
  std::vector<std::string> names()
  {
    if (m_result)
      return m_result->names;
    m_result->GetValue(0, 0);
    return std::vector<std::string>();
  }
  int columnCount() {
    if (m_result)
      return m_result->ColumnCount();
    return -1;
  }
  int chunk() {
    auto chonk = m_result->Fetch();
    fmt::print("We have {} columns and {} values\n", chonk->ColumnCount(), chonk->size());
    auto i = chonk->data[0];
    fmt::print("A column with {} values and {} type\n", i.GetValue(0).ToString(), i.GetType().ToString());
    int* values = reinterpret_cast<int*>(i.GetData());
    fmt::print("{}, {}, {}\n", values[0], values[1], values[3]);
    return chonk->size();
  }
private:
  std::unique_ptr<duckdb::MaterializedQueryResult> m_result;
};

export class Database
{
public:
  Database();
  ~Database() = default;
  
  QueryResult query(std::string query);
  void print(std::string query);

private:
  std::unique_ptr<duckdb::DuckDB> m_database;
  std::unique_ptr<duckdb::Connection> m_conn;
};

Database::Database()
{
  m_database = std::make_unique<duckdb::DuckDB>(nullptr);
  m_conn = std::make_unique<duckdb::Connection>(*m_database);
}

QueryResult Database::query(std::string query)
{
  QueryResult result(m_conn->Query(query));
  return result;

}

void Database::print(std::string query)
{
  auto result = m_conn->Query(query);
  //result->Print();
}

}
