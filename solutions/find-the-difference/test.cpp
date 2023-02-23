#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

TEST_CASE("Simple") {
  REQUIRE('e' == Solution::findTheDifference("abcd", "abcde"));
  REQUIRE('y' == Solution::findTheDifference("", "y"));
}
