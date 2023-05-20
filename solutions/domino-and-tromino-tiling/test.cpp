#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::numTilings(1));
  REQUIRE(2 == Solution::numTilings(2));
  REQUIRE(5 == Solution::numTilings(3));
}
