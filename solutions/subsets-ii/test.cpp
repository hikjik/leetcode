#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

void CheckSolution(std::vector<int> nums,
                   std::vector<std::vector<int>> expected) {
  auto actual = Solution::subsetsWithDup(nums);
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> expected{{},     {1},    {2},    {3},
                                           {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};
    CheckSolution(nums, expected);
  }
  {
    std::vector<int> nums{1, 2, 2};
    std::vector<std::vector<int>> expected{{},     {1},    {2},
                                           {1, 2}, {2, 2}, {1, 2, 2}};
    CheckSolution(nums, expected);
  }
  {
    std::vector<int> nums{0};
    std::vector<std::vector<int>> expected{{}, {0}};
    CheckSolution(nums, expected);
  }
}
