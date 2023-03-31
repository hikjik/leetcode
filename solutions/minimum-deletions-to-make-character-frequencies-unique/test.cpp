#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::minDeletions("aab"));
  REQUIRE(2 == Solution::minDeletions("aaabbbcc"));
  REQUIRE(2 == Solution::minDeletions("ceabaacb"));
}
