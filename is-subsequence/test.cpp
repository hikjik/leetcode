#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(true == Solution::isSubsequence("abc", "aahbgdcdd"));
  REQUIRE(false == Solution::isSubsequence("axc", "ahbgdc"));
  REQUIRE(false == Solution::isSubsequence("aaaaaa", "bbaaaa"));
}
