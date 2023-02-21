#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE_FALSE(Solution::canConstruct("a", "b"));
  REQUIRE_FALSE(Solution::canConstruct("aa", "ab"));
  REQUIRE(Solution::canConstruct("aa", "aab"));
}