#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(9 == Solution::reverse(900000));
  REQUIRE(321 == Solution::reverse(123));
  REQUIRE(-321 == Solution::reverse(-123));
  REQUIRE(21 == Solution::reverse(120));
}
