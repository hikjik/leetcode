#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 0;
    std::vector<int> nums{1};
    REQUIRE(0 == Solution::smallestRangeII(nums, k));
  }
  {
    int k = 2;
    std::vector<int> nums{0, 10};
    REQUIRE(6 == Solution::smallestRangeII(nums, k));
  }
  {
    int k = 3;
    std::vector<int> nums{1, 3, 6};
    REQUIRE(3 == Solution::smallestRangeII(nums, k));
  }
}