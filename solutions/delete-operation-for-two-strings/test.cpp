#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::minDistance("sea", "eat"));
  REQUIRE(4 == Solution::minDistance("leetcode", "etco"));
}
