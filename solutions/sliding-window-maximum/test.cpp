#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> expected{3, 3, 5, 5, 6, 7};
    REQUIRE(expected == Solution::maxSlidingWindow(nums, k));
  }
  {
    int k = 1;
    std::vector<int> nums{1};
    std::vector<int> expected{1};
    REQUIRE(expected == Solution::maxSlidingWindow(nums, k));
  }
}
