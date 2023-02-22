#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{7, 1, 5, 3, 6, 4};
    REQUIRE(7 == Solution::maxProfit(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 5};
    REQUIRE(4 == Solution::maxProfit(nums));
  }
  {
    std::vector<int> nums{7, 6, 4, 3, 1};
    REQUIRE(0 == Solution::maxProfit(nums));
  }
}
