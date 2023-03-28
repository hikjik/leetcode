#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::longestIdealString("acfgbd", 2));
  REQUIRE(4 == Solution::longestIdealString("abcd", 3));
}
