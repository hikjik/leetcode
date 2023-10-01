#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    REQUIRE("abc" == Solution::smallestSubsequence("bcabc"));
    REQUIRE("acdb" == Solution::smallestSubsequence("cbacdcbc"));
    REQUIRE("c" == Solution::smallestSubsequence("cccccc"));
  }
}
