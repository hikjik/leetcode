#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(int x, const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = Solution::partition(VectorToList(values), x);
  REQUIRE(expected == ListToVector(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    int x = 3;
    std::vector<int> values{1, 4, 3, 2, 5, 2};
    std::vector<int> expected{1, 2, 2, 4, 3, 5};
    CheckSolution(x, values, expected);
  }
  {
    int x = 2;
    std::vector<int> values{2, 1};
    std::vector<int> expected{1, 2};
    CheckSolution(x, values, expected);
  }
}
