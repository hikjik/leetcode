#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::minDistance("horse", "ros"));
  REQUIRE(5 == Solution::minDistance("intention", "execution"));
}
