#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::minInsertions("zzazz"));
  REQUIRE(2 == Solution::minInsertions("mbadm"));
  REQUIRE(5 == Solution::minInsertions("leetcode"));
}
