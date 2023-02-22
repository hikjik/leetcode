#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{8, 1, 5, 2, 6};
    REQUIRE(11 == Solution::maxScoreSightseeingPair(nums));
  }
  {
    std::vector<int> nums{1, 2};
    REQUIRE(2 == Solution::maxScoreSightseeingPair(nums));
  }
}
