#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::addDigits(38));
  REQUIRE(0 == Solution::addDigits(0));
}
