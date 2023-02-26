#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(3 == Solution::numberOfArithmeticSlices(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE(0 == Solution::numberOfArithmeticSlices(nums));
  }
  {
    std::vector<int> nums{1, 2};
    REQUIRE(0 == Solution::numberOfArithmeticSlices(nums));
  }
}
