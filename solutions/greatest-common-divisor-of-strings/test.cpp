#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("ABC" == Solution::gcdOfStrings("ABCABC", "ABC"));
  REQUIRE("AB" == Solution::gcdOfStrings("ABABAB", "ABAB"));
  REQUIRE("" == Solution::gcdOfStrings("LEET", "CODE"));
}
