#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("III" == Solution::intToRoman(3));
  REQUIRE("LVIII" == Solution::intToRoman(58));
  REQUIRE("MCMXCIV" == Solution::intToRoman(1994));
  REQUIRE("MMXXIII" == Solution::intToRoman(2023));
}
