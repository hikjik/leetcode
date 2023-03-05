#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 2, 3};
    REQUIRE(Solution::isMonotonic(nums));
  }
  {
    std::vector<int> nums{6, 5, 4, 4};
    REQUIRE(Solution::isMonotonic(nums));
  }
  {
    std::vector<int> nums{1, 3, 2};
    REQUIRE_FALSE(Solution::isMonotonic(nums));
  }
}
