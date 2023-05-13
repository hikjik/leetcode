#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(8 == Solution::countGoodStrings(3, 3, 1, 1));
  REQUIRE(5 == Solution::countGoodStrings(2, 3, 1, 2));
}
