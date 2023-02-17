#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> costs{10, 15, 20};
    REQUIRE(15 == Solution::minCostClimbingStairs(costs));
  }
  {
    std::vector<int> costs{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    REQUIRE(6 == Solution::minCostClimbingStairs(costs));
  }
}
