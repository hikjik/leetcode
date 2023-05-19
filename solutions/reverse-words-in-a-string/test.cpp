#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("blue is sky the" == Solution::reverseWords("the sky is blue"));
  REQUIRE("world hello" == Solution::reverseWords("  hello world  "));
  REQUIRE("example good a" == Solution::reverseWords("a good   example"));
}
