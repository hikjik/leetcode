#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// K = row.size()
// L = name.size()
// Time: O(QK+QL)
// Space: O(QK+QL)

class Table {
public:
  void insertRow(std::vector<std::string> row) { rows[id++] = std::move(row); }

  void deleteRow(int rowId) { rows.erase(rowId); }

  std::string selectCell(int rowId, int colId) {
    return rows[rowId][colId - 1];
  }

private:
  std::unordered_map<int, std::vector<std::string>> rows;
  int id = 1;
};

class SQL {
public:
  // O(1)
  SQL([[maybe_unused]] const std::vector<std::string> &names,
      [[maybe_unused]] const std::vector<int> &columns) {}

  // O(K+L)
  void insertRow(std::string name, std::vector<std::string> row) {
    tables[name].insertRow(std::move(row));
  }

  // O(L)
  void deleteRow(std::string name, int rowId) { tables[name].deleteRow(rowId); }

  // O(L)
  std::string selectCell(std::string name, int rowId, int columnId) {
    return tables[name].selectCell(rowId, columnId);
  }

private:
  std::unordered_map<std::string, Table> tables;
};
