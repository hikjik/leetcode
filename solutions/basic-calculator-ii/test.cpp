#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(7 == Solution::calculate("3+2*2"));
  REQUIRE(1 == Solution::calculate(" 3/2 "));
  REQUIRE(5 == Solution::calculate(" 3+5 / 2 "));
  REQUIRE(14 == Solution::calculate(" 1 - 2 + 3 + 4*3*1 + 5 /6 "));
}
