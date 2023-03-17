#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  Solution::reorderList(head);
  REQUIRE(expected == ListToVector(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 4};
    std::vector<int> expected{1, 4, 2, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 5, 2, 4, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1};
    std::vector<int> expected{1};
    CheckSolution(values, expected);
  }
}
