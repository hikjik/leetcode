#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> nums{1, 2, 3, 4};
  REQUIRE(13 == Solution::rangeSum(nums, 4, 1, 5));
  REQUIRE(6 == Solution::rangeSum(nums, 4, 3, 4));
  REQUIRE(50 == Solution::rangeSum(nums, 4, 1, 10));
}
