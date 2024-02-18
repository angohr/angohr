// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

module;

#include <duckdb.hpp>

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
    return std::vector<std::string>();
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
  result->Print();
}

}
