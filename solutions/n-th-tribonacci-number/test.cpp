#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::tribonacci(0));
  REQUIRE(1 == Solution::tribonacci(1));
  REQUIRE(1 == Solution::tribonacci(2));
  REQUIRE(4 == Solution::tribonacci(4));
  REQUIRE(1389537 == Solution::tribonacci(25));
}
