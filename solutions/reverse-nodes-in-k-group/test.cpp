#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(int k, const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto modified = Solution::reverseKGroup(head, k);

  REQUIRE(expected == ListToVector(modified));

  FreeList(modified);
}

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> values{1, 2, 3, 4};
    std::vector<int> expected{2, 1, 4, 3};
    CheckSolution(k, values, expected);
  }
  {
    int k = 2;
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{2, 1, 4, 3, 5};
    CheckSolution(k, values, expected);
  }
  {
    int k = 3;
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{3, 2, 1, 4, 5};
    CheckSolution(k, values, expected);
  }
}
