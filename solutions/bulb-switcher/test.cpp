#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::bulbSwitch(0));
  REQUIRE(1 == Solution::bulbSwitch(1));
  REQUIRE(1 == Solution::bulbSwitch(3));
  REQUIRE(2 == Solution::bulbSwitch(5));
  REQUIRE(3 == Solution::bulbSwitch(10));
  REQUIRE(4 == Solution::bulbSwitch(16));
}
