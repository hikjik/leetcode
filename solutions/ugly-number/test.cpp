#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isUgly(6));
  REQUIRE(Solution::isUgly(1));
  REQUIRE_FALSE(Solution::isUgly(14));
  REQUIRE_FALSE(Solution::isUgly(0));
  REQUIRE_FALSE(Solution::isUgly(-1));
}