#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isHappy(19));
  REQUIRE_FALSE(Solution::isHappy(2));
}