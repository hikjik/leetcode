#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::titleToNumber("A"));
  REQUIRE(28 == Solution::titleToNumber("AB"));
  REQUIRE(701 == Solution::titleToNumber("ZY"));
}