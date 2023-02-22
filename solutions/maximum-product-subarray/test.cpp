#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 3, -2, 4};
    REQUIRE(6 == Solution::maxProduct(nums));
  }
  {
    std::vector<int> nums{-2, 0, -1};
    REQUIRE(0 == Solution::maxProduct(nums));
  }
  {
    std::vector<int> nums{-4, -3, -2};
    REQUIRE(12 == Solution::maxProduct(nums));
  }
}
