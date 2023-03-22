#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 5, 4, 7};
    REQUIRE(2 == Solution::findNumberOfLIS(nums));
  }
  {
    std::vector<int> nums{2, 2, 2, 2, 2};
    REQUIRE(5 == Solution::findNumberOfLIS(nums));
  }
}