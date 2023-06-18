#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 1, 3};
    REQUIRE(1 == Solution::numOfWays(nums));
  }
  {
    std::vector<int> nums{3, 4, 5, 1, 2};
    REQUIRE(5 == Solution::numOfWays(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(0 == Solution::numOfWays(nums));
  }
}
