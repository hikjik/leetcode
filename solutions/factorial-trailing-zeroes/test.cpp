#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::trailingZeroes(0));
  REQUIRE(0 == Solution::trailingZeroes(3));
  REQUIRE(1 == Solution::trailingZeroes(5));
  REQUIRE(24 == Solution::trailingZeroes(100));
}
