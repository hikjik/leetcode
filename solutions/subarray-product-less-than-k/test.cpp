#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 100;
    std::vector<int> nums{10, 5, 2, 6};
    REQUIRE(8 == Solution::numSubarrayProductLessThanK(nums, k));
  }
  {
    int k = 0;
    std::vector<int> nums{1, 2, 3};
    REQUIRE(0 == Solution::numSubarrayProductLessThanK(nums, k));
  }
  {
    int k = 50;
    std::vector<int> nums{100, 1, 2, 3};
    REQUIRE(6 == Solution::numSubarrayProductLessThanK(nums, k));
  }
}
