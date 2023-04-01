#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  REQUIRE(expected == Solution::nodesBetweenCriticalPoints(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{3, 1};
    std::vector<int> expected{-1, -1};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{5, 3, 1, 2, 5, 1, 2};
    std::vector<int> expected{1, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 3, 2, 2, 3, 2, 2, 2, 7};
    std::vector<int> expected{3, 3};
    CheckSolution(values, expected);
  }
}
