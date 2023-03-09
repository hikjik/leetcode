#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 34;
    std::vector<int> nums{1, 2, 0, 0};
    std::vector<int> expected{1, 2, 3, 4};
    REQUIRE(expected == Solution::addToArrayForm(nums, k));
  }
  {
    int k = 181;
    std::vector<int> nums{2, 7, 4};
    std::vector<int> expected{4, 5, 5};
    REQUIRE(expected == Solution::addToArrayForm(nums, k));
  }
  {
    int k = 806;
    std::vector<int> nums{2, 1, 5};
    std::vector<int> expected{1, 0, 2, 1};
    REQUIRE(expected == Solution::addToArrayForm(nums, k));
  }
}
