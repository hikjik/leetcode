#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::characterReplacement("ABAB", 2));
  REQUIRE(4 == Solution::characterReplacement("AABABBA", 1));
}
