#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("BANC" == Solution::minWindow("ADOBECODEBANC", "ABC"));
  REQUIRE("a" == Solution::minWindow("a", "a"));
  REQUIRE("" == Solution::minWindow("a", "aa"));
}
