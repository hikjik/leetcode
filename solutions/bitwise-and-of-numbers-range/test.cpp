#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::rangeBitwiseAnd(5, 7));
  REQUIRE(0 == Solution::rangeBitwiseAnd(0, 0));
  REQUIRE(0 == Solution::rangeBitwiseAnd(1, 2147483647));
}
