#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    std::vector<int> expected{3, 4};
    REQUIRE(expected == Solution::searchRange(nums, 8));
  }
  {
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    std::vector<int> expected{-1, -1};
    REQUIRE(expected == Solution::searchRange(nums, 6));
  }
  {
    std::vector<int> nums;
    std::vector<int> expected{-1, -1};
    REQUIRE(expected == Solution::searchRange(nums, 0));
  }
}
