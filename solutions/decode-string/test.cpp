#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("aaabcbc" == Solution::decodeString("3[a]2[bc]"));
  REQUIRE("accaccacc" == Solution::decodeString("3[a2[c]]"));
  REQUIRE("abcabccdcdcdef" == Solution::decodeString("2[abc]3[cd]ef"));
}
