#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::firstUniqChar("leetcode"));
  REQUIRE(2 == Solution::firstUniqChar("loveleetcode"));
  REQUIRE(-1 == Solution::firstUniqChar("aabb"));
}
