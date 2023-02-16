#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::countOdds(3, 7));
  REQUIRE(1 == Solution::countOdds(8, 10));
}
