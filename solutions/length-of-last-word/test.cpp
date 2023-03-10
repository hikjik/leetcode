#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(5 == Solution::lengthOfLastWord("Hello World"));
  REQUIRE(4 == Solution::lengthOfLastWord("   fly me   to   the moon  "));
  REQUIRE(6 == Solution::lengthOfLastWord("luffy is still joyboy"));
}
