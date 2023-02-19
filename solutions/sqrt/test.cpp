#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::mySqrt(0));
  REQUIRE(1 == Solution::mySqrt(1));
  REQUIRE(1 == Solution::mySqrt(2));
  REQUIRE(1 == Solution::mySqrt(3));
  REQUIRE(2 == Solution::mySqrt(4));
  REQUIRE(2 == Solution::mySqrt(5));
  REQUIRE(2 == Solution::mySqrt(6));
  REQUIRE(2 == Solution::mySqrt(7));
  REQUIRE(2 == Solution::mySqrt(8));
  REQUIRE(3 == Solution::mySqrt(9));
}
