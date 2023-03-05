#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    REQUIRE(4 == Solution::lengthOfLIS(nums));
  }
  {
    std::vector<int> nums{0, 1, 0, 3, 2, 3};
    REQUIRE(4 == Solution::lengthOfLIS(nums));
  }
  {
    std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};
    REQUIRE(1 == Solution::lengthOfLIS(nums));
  }
}
