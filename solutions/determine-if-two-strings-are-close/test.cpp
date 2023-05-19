#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::closeStrings("abc", "bca"));
  REQUIRE_FALSE(Solution::closeStrings("a", "aa"));
  REQUIRE(Solution::closeStrings("cabbba", "abbccc"));
}
