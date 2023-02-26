#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::numDecodings("12"));
  REQUIRE(3 == Solution::numDecodings("226"));
  REQUIRE(0 == Solution::numDecodings("06"));
}
