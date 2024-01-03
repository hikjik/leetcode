#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<Employee> employees;
    int id;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .employees{{1, 5, {2, 3}}, {2, 3, {}}, {3, 3, {}}},
          .id = 1,
          .expected = 11,
      },
      {
          .employees{{1, 2, {5}}, {5, -3, {}}},
          .id = 5,
          .expected = -3,
      },
  };

  SECTION("BFS") {
    for (auto &[employees, id, expected] : test_cases) {
      std::vector<Employee *> ptrs;
      for (auto &employee : employees) {
        ptrs.push_back(&employee);
      }
      const auto actual = bfs::Solution::getImportance(ptrs, id);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (auto &[employees, id, expected] : test_cases) {
      std::vector<Employee *> ptrs;
      for (auto &employee : employees) {
        ptrs.push_back(&employee);
      }
      const auto actual = dfs::Solution::getImportance(ptrs, id);
      REQUIRE(expected == actual);
    }
  }
}
