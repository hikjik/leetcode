#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(true == Solution::isIsomorphic("egg", "add"));
  REQUIRE(false == Solution::isIsomorphic("foo", "bar"));
  REQUIRE(true == Solution::isIsomorphic("paper", "title"));
  REQUIRE(false == Solution::isIsomorphic("badc", "baba"));
}
