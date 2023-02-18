#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(12 == Solution::nthUglyNumber(10));
  REQUIRE(1 == Solution::nthUglyNumber(1));
  REQUIRE(2048 == Solution::nthUglyNumber(110));
  REQUIRE(2123366400 == Solution::nthUglyNumber(1690));
}