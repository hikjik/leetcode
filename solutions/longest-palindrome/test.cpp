#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(7 == Solution::longestPalindrome("abccccdd"));
  REQUIRE(1 == Solution::longestPalindrome("a"));
  REQUIRE(4 == Solution::longestPalindrome("aaaa"));
  REQUIRE(7 == Solution::longestPalindrome("aaaAaaaa"));
}
