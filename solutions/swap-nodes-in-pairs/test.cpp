#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto modified = Solution::swapPairs(head);
  REQUIRE(expected == ListToVector(modified));
  FreeList(modified);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 4};
    std::vector<int> expected{2, 1, 4, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 2, 3};
    std::vector<int> expected{2, 1, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values;
    std::vector<int> expected;
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1};
    std::vector<int> expected{1};
    CheckSolution(values, expected);
  }
}
