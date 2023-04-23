#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isPalindrome("A man, a plan, a canal: Panama"));
  REQUIRE_FALSE(Solution::isPalindrome("race a car"));
  REQUIRE(Solution::isPalindrome(" "));
}
