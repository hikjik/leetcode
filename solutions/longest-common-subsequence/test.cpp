#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::longestCommonSubsequence("abcde", "ace"));
  REQUIRE(3 == Solution::longestCommonSubsequence("abc", "abc"));
  REQUIRE(0 == Solution::longestCommonSubsequence("abc", "def"));
}
