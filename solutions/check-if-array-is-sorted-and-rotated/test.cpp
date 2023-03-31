#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 4, 5, 1, 2};
    REQUIRE(Solution::check(nums));
  }
  {
    std::vector<int> nums{2, 1, 3, 4};
    REQUIRE_FALSE(Solution::check(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(Solution::check(nums));
  }
}
