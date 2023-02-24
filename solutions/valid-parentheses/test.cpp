#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isValid("()"));
  REQUIRE(Solution::isValid("()[]{}"));
  REQUIRE_FALSE(Solution::isValid("(]"));
}
