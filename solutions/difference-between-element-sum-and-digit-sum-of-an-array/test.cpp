#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 15, 6, 3};
    REQUIRE(9 == Solution::differenceOfSum(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(0 == Solution::differenceOfSum(nums));
  }
}
