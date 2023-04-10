#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::maxValue(4, 2, 6));
  REQUIRE(3 == Solution::maxValue(6, 1, 10));
  REQUIRE(155230825 == Solution::maxValue(6, 2, 931384943));
  REQUIRE(4 == Solution::maxValue(8, 7, 14));
}
