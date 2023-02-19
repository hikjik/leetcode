#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::areAlmostEqual("bank", "kanb"));
  REQUIRE(Solution::areAlmostEqual("kelb", "kelb"));
  REQUIRE_FALSE(Solution::areAlmostEqual("attack", "defend"));
  REQUIRE_FALSE(Solution::areAlmostEqual("abcd", "dcba"));
}
