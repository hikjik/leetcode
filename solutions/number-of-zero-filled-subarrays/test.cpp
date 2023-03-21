#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 0, 0, 2, 0, 0, 4};
    REQUIRE(6 == Solution::zeroFilledSubarray(nums));
  }
  {
    std::vector<int> nums{0, 0, 0, 2, 0, 0};
    REQUIRE(9 == Solution::zeroFilledSubarray(nums));
  }
  {
    std::vector<int> nums{2, 10, 2019};
    REQUIRE(0 == Solution::zeroFilledSubarray(nums));
  }
}
