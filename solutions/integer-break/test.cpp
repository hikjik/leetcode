#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::integerBreak(2));
  REQUIRE(2 == Solution::integerBreak(3));
  REQUIRE(4 == Solution::integerBreak(4));
  REQUIRE(6 == Solution::integerBreak(5));
  REQUIRE(9 == Solution::integerBreak(6));
  REQUIRE(12 == Solution::integerBreak(7));
  REQUIRE(18 == Solution::integerBreak(8));
  REQUIRE(27 == Solution::integerBreak(9));
  REQUIRE(36 == Solution::integerBreak(10));
}
