#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::climbStairs(2));
  REQUIRE(3 == Solution::climbStairs(3));
}
