#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4, 5};
    REQUIRE(Solution::increasingTriplet(nums));
  }
  {
    std::vector<int> nums{5, 4, 3, 2, 1};
    REQUIRE_FALSE(Solution::increasingTriplet(nums));
  }
  {
    std::vector<int> nums{2, 1, 5, 0, 4, 6};
    REQUIRE(Solution::increasingTriplet(nums));
  }
}
