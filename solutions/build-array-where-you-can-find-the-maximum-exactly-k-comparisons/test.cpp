#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(6 == Solution::numOfArrays(2, 3, 1));
  REQUIRE(0 == Solution::numOfArrays(5, 2, 3));
  REQUIRE(1 == Solution::numOfArrays(9, 1, 1));
}
