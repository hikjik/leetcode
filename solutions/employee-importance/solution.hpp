#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

// Definition for Employee.
struct Employee {
  Employee(int id, int importance, std::vector<int> subordinates)
      : id(id), importance(importance), subordinates(std::move(subordinates)) {}

  int id;
  int importance;
  std::vector<int> subordinates;
};

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int getImportance(const std::vector<Employee *> &employees, int id) {
    std::unordered_map<int, Employee *> idToEmployee;
    for (auto *employee : employees) {
      idToEmployee[employee->id] = employee;
    }

    std::queue<int> queue{{id}};
    int ans = 0;
    while (!queue.empty()) {
      const auto *employee = idToEmployee[queue.front()];
      queue.pop();

      ans += employee->importance;
      for (auto id : employee->subordinates) {
        queue.push(id);
      }
    }
    return ans;
  }
};

} // namespace bfs

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int getImportance(const std::vector<Employee *> &employees, int id) {
    std::unordered_map<int, Employee *> idToEmployee;
    for (auto *employee : employees) {
      idToEmployee[employee->id] = employee;
    }

    return getImportance(idToEmployee, idToEmployee.at(id));
  }

  static int
  getImportance(const std::unordered_map<int, Employee *> &idToEmployee,
                Employee *employee) {
    auto ans = employee->importance;
    for (auto id : employee->subordinates) {
      ans += getImportance(idToEmployee, idToEmployee.at(id));
    }
    return ans;
  }
};

} // namespace dfs
