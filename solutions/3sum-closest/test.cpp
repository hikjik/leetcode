#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 1;
    std::vector<int> nums{-1, 2, 1, -4};
    REQUIRE(2 == Solution::threeSumClosest(nums, target));
  }
  {
    int target = 1;
    std::vector<int> nums{0, 0, 0};
    REQUIRE(0 == Solution::threeSumClosest(nums, target));
  }
}
