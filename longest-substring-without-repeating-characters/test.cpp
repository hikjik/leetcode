#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::lengthOfLongestSubstring("abcabcbb"));
  REQUIRE(1 == Solution::lengthOfLongestSubstring("bbbbb"));
  REQUIRE(3 == Solution::lengthOfLongestSubstring("pwwkew"));
}
