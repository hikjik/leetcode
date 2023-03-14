#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<std::vector<int>> &prerequisites,
                   int num_courses, bool cycle) {
  auto actual = Solution::findOrder(num_courses, prerequisites);
  if (cycle) {
    REQUIRE(actual.empty());
    return;
  }

  REQUIRE(num_courses * 1UL == actual.size());

  std::unordered_map<int, int> positions;
  for (size_t i = 0; i < actual.size(); ++i) {
    positions[actual[i]] = i;
  }
  REQUIRE(num_courses * 1UL == positions.size());
  for (const auto &edge : prerequisites) {
    REQUIRE(positions[edge[0]] > positions[edge[1]]);
  }
}

TEST_CASE("Simple") {
  {
    int num_courses = 2;
    std::vector<std::vector<int>> prerequisites{{1, 0}};
    CheckSolution(prerequisites, num_courses, false);
  }
  {
    int num_courses = 4;
    std::vector<std::vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    CheckSolution(prerequisites, num_courses, false);
  }
  {
    int num_courses = 1;
    std::vector<std::vector<int>> prerequisites;
    CheckSolution(prerequisites, num_courses, false);
  }
  {
    int num_courses = 2;
    std::vector<std::vector<int>> prerequisites{{0, 1}, {1, 0}};
    CheckSolution(prerequisites, num_courses, true);
  }
  {
    int num_courses = 3;
    std::vector<std::vector<int>> prerequisites{{1, 0}, {1, 2}, {0, 1}};
    CheckSolution(prerequisites, num_courses, true);
  }
}
