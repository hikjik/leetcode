#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 5, 9};
    int threshold = 6;
    REQUIRE(5 == Solution::smallestDivisor(nums, threshold));
  }
  {
    std::vector<int> nums{44, 22, 33, 11, 1};
    int threshold = 5;
    REQUIRE(44 == Solution::smallestDivisor(nums, threshold));
  }
}