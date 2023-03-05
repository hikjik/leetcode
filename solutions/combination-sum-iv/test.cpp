#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3};
    int target = 4;
    REQUIRE(7 == Solution::combinationSum4(nums, target));
  }
  {
    std::vector<int> nums{9};
    int target = 3;
    REQUIRE(0 == Solution::combinationSum4(nums, target));
  }
}
