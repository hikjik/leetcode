#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::maxVowels("abciiidef", 3));
  REQUIRE(2 == Solution::maxVowels("aeiou", 2));
  REQUIRE(2 == Solution::maxVowels("aebbb", 2));
  REQUIRE(2 == Solution::maxVowels("bbbaa", 2));
  REQUIRE(2 == Solution::maxVowels("leetcode", 3));
}
