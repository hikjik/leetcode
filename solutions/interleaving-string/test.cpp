#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isInterleave("aabcc", "dbbca", "aadbbcbcac"));
  REQUIRE_FALSE(Solution::isInterleave("aabcc", "dbbca", "aadbbbaccc"));
  REQUIRE(Solution::isInterleave("", "", ""));
  REQUIRE(Solution::isInterleave("", "b", "b"));
  REQUIRE_FALSE(Solution::isInterleave("db", "b", "cbb"));
}
