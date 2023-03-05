#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::numSquares(12));
  REQUIRE(2 == Solution::numSquares(13));
}
