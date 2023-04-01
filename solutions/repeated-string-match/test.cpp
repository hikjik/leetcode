#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::repeatedStringMatch("abcd", "cdabcdab"));
  REQUIRE(2 == Solution::repeatedStringMatch("a", "aa"));
  REQUIRE(1 == Solution::repeatedStringMatch("aaac", "aac"));
  REQUIRE(-1 == Solution::repeatedStringMatch("acbq", "def"));
  REQUIRE(-1 == Solution::repeatedStringMatch("abc", "wxyz"));
}
