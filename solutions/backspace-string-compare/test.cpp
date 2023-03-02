#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::backspaceCompare("ab#c", "ad#c"));
  REQUIRE(Solution::backspaceCompare("ab##", "c#d#"));
  REQUIRE_FALSE(Solution::backspaceCompare("a#c", "b"));
  REQUIRE(Solution::backspaceCompare("bxj##tw", "bxo#j##tw"));
  REQUIRE(Solution::backspaceCompare("nzp#o#g", "b#nzp#o#g"));
  REQUIRE(Solution::backspaceCompare("p#", "b#"));
  REQUIRE_FALSE(Solution::backspaceCompare("a", "aa"));
}
