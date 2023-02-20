#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &values, int n,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto modified = Solution::removeNthFromEnd(head, n);

  REQUIRE(expected == ListToVector(modified));

  FreeList(modified);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 5};
    CheckSolution(values, 2, expected);
  }
  {
    std::vector<int> values{1, 2};
    std::vector<int> expected{1};
    CheckSolution(values, 1, expected);
  }
  {
    std::vector<int> values{1};
    std::vector<int> expected;
    CheckSolution(values, 1, expected);
  }
}
