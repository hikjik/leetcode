#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    REQUIRE("abc" == Solution::removeDuplicateLetters("bcabc"));
    REQUIRE("acdb" == Solution::removeDuplicateLetters("cbacdcbc"));
    REQUIRE("c" == Solution::removeDuplicateLetters("cccccc"));
  }
}
