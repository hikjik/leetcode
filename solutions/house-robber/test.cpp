#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 1};
    REQUIRE(4 == Solution::rob(nums));
  }
  {
    std::vector<int> nums{2, 7, 9, 3, 1};
    REQUIRE(12 == Solution::rob(nums));
  }
}
