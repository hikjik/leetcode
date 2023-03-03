#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::strStr("sadbutsad", "sad"));
  REQUIRE(-1 == Solution::strStr("leetcode", "leeto"));
  REQUIRE(8 == Solution::strStr("advleefvleetorsa", "leeto"));
}
