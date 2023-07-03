#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::buddyStrings("ab", "ba"));
  REQUIRE_FALSE(Solution::buddyStrings("ab", "ab"));
  REQUIRE(Solution::buddyStrings("aa", "aa"));
}
