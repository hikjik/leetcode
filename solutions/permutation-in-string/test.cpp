#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::checkInclusion("ab", "eidbaooo"));
  REQUIRE_FALSE(Solution::checkInclusion("ab", "eidboaoo"));
  REQUIRE_FALSE(Solution::checkInclusion("abc", "ab"));
}
