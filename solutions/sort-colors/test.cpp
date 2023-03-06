#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 0, 2, 1, 1, 0};
    std::vector<int> expected{0, 0, 1, 1, 2, 2};
    Solution::sortColors(nums);
    REQUIRE(expected == nums);
  }
  {
    std::vector<int> nums{2, 0, 1};
    std::vector<int> expected{0, 1, 2};
    Solution::sortColors(nums);
    REQUIRE(expected == nums);
  }
}
