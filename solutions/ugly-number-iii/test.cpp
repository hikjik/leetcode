#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::nthUglyNumber(3, 2, 3, 5));
  REQUIRE(6 == Solution::nthUglyNumber(4, 2, 3, 4));
  REQUIRE(10 == Solution::nthUglyNumber(5, 2, 11, 13));
}
