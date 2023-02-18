#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isPerfectSquare(16));
  REQUIRE(Solution::isPerfectSquare(1));
  REQUIRE_FALSE(Solution::isPerfectSquare(14));
}

TEST_CASE("Overflow") {
  REQUIRE_FALSE(Solution::isPerfectSquare(2147483647));
  REQUIRE(Solution::isPerfectSquare(1975269136));
}