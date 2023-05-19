#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  head = Solution::deleteMiddle(head);
  REQUIRE(expected == ListToVector(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 3, 4, 7, 1, 2, 6};
    std::vector<int> expected{1, 3, 4, 1, 2, 6};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 2, 3, 4};
    std::vector<int> expected{1, 2, 4};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 2};
    std::vector<int> expected{1};
    CheckSolution(values, expected);
  }
}
