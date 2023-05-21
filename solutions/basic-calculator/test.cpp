#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::calculate("1 + 1"));
  REQUIRE(3 == Solution::calculate(" 2-1 + 2 "));
  REQUIRE(23 == Solution::calculate("(1+(4+5+2)-3)+(6+8)"));
}
