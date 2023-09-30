#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE_FALSE(Solution::find132pattern(nums));
  }
  {
    std::vector<int> nums{3, 1, 4, 2};
    REQUIRE(Solution::find132pattern(nums));
  }
  {
    std::vector<int> nums{-1, 3, 2, 0};
    REQUIRE(Solution::find132pattern(nums));
  }
  {
    std::vector<int> nums{1, 0, 1, -4, -3};
    REQUIRE_FALSE(Solution::find132pattern(nums));
  }
}
