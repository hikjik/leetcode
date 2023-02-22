#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, -2, -3, 4};
    REQUIRE(4 == Solution::getMaxLen(nums));
  }
  {
    std::vector<int> nums{0, 1, -2, -3, -4};
    REQUIRE(3 == Solution::getMaxLen(nums));
  }
  {
    std::vector<int> nums{-1, -2, -3, 0, 1};
    REQUIRE(2 == Solution::getMaxLen(nums));
  }
  {
    std::vector<int> nums{-16, 0, -5, 2, 2, -13, 11, 8};
    REQUIRE(6 == Solution::getMaxLen(nums));
  }
}
