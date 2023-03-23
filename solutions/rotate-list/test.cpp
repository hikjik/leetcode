#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(int k, const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto rotated = Solution::rotateRight(head, k);
  REQUIRE(expected == ListToVector(rotated));
  FreeList(rotated);
}

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{4, 5, 1, 2, 3};
    CheckSolution(k, values, expected);
  }
  {
    int k = 4;
    std::vector<int> values{0, 1, 2};
    std::vector<int> expected{2, 0, 1};
    CheckSolution(k, values, expected);
  }
  {
    int k = 3;
    std::vector<int> values{0, 1, 2};
    std::vector<int> expected{0, 1, 2};
    CheckSolution(k, values, expected);
  }
  {
    int k = 5;
    std::vector<int> values;
    std::vector<int> expected;
    CheckSolution(k, values, expected);
  }
  {
    int k = 5;
    std::vector<int> values{1};
    std::vector<int> expected{1};
    CheckSolution(k, values, expected);
  }
}
