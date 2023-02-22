#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &values, int val,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto modified = Solution::removeElements(head, val);

  REQUIRE(expected == ListToVector(modified));

  FreeList(modified);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    std::vector<int> expected{1, 2, 3, 4, 5};
    CheckSolution(values, val, expected);
  }
  {
    std::vector<int> values;
    int val = 1;
    std::vector<int> expected;
    CheckSolution(values, val, expected);
  }
  {
    std::vector<int> values{7, 7, 7, 7};
    int val = 7;
    std::vector<int> expected;
    CheckSolution(values, val, expected);
  }
}
