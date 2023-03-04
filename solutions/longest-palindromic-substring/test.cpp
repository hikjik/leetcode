#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("bab" == Solution::longestPalindrome("babad"));
  REQUIRE("bb" == Solution::longestPalindrome("cbbd"));
}
