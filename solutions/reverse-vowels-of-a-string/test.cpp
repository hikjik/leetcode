#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("holle" == Solution::reverseVowels("hello"));
  REQUIRE("leotcede" == Solution::reverseVowels("leetcode"));
}
