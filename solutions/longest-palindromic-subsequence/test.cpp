#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::longestPalindromeSubseq("bbbab"));
  REQUIRE(2 == Solution::longestPalindromeSubseq("cbbd"));
  REQUIRE(1 == Solution::longestPalindromeSubseq("abcdef"));
}
