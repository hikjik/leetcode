#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{0, 1, 0, 3, 12};
    std::vector<int> expected{1, 3, 12, 0, 0};
    Solution::moveZeroes(nums);
    REQUIRE(expected == nums);
  }
  {
    std::vector<int> nums{1, 1, 0, 3, 12};
    std::vector<int> expected{1, 1, 3, 12, 0};
    Solution::moveZeroes(nums);
    REQUIRE(expected == nums);
  }
  {
    std::vector<int> nums{0};
    std::vector<int> expected{0};
    Solution::moveZeroes(nums);
    REQUIRE(expected == nums);
  }
}
