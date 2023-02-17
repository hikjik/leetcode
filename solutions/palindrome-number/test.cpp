#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  { REQUIRE(true == Solution::isPalindrome(121)); }
  { REQUIRE(false == Solution::isPalindrome(-121)); }
  { REQUIRE(false == Solution::isPalindrome(10)); }
}
