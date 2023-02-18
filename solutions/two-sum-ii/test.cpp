#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 7, 11, 15};
    std::vector<int> expected{1, 2};
    REQUIRE(expected == Solution::twoSum(nums, 9));
  }
  {
    std::vector<int> nums{2, 3, 4};
    std::vector<int> expected{1, 3};
    REQUIRE(expected == Solution::twoSum(nums, 6));
  }
  {
    std::vector<int> nums{-1, 0};
    std::vector<int> expected{1, 2};
    REQUIRE(expected == Solution::twoSum(nums, -1));
  }
  {
    std::vector<int> nums{-3, 3, 4, 90};
    std::vector<int> expected{1, 2};
    REQUIRE(expected == Solution::twoSum(nums, 0));
  }
}
