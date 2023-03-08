#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::repeatedSubstringPattern("abab"));
  REQUIRE(Solution::repeatedSubstringPattern("abcabcabcabc"));
  REQUIRE_FALSE(Solution::repeatedSubstringPattern("aba"));
}
