#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    REQUIRE(6 == Solution::maxSubArray(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE(1 == Solution::maxSubArray(nums));
  }
  {
    std::vector<int> nums{5, 4, -1, 7, 8};
    REQUIRE(23 == Solution::maxSubArray(nums));
  }
}
