#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::romanToInt("III"));
  REQUIRE(58 == Solution::romanToInt("LVIII"));
  REQUIRE(1994 == Solution::romanToInt("MCMXCIV"));
}
