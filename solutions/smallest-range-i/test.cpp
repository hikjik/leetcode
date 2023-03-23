#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> nums{1};
    REQUIRE(0 == Solution::smallestRangeI(nums, k));
  }
  {
    int k = 2;
    std::vector<int> nums{0, 10};
    REQUIRE(6 == Solution::smallestRangeI(nums, k));
  }
  {
    int k = 3;
    std::vector<int> nums{1, 3, 6};
    REQUIRE(0 == Solution::smallestRangeI(nums, k));
  }
}