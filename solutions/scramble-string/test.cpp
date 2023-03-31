#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE_FALSE(Solution().isScramble("eebaacbcbcadaaedceaaacadccd",
                                      "eadcaacabaddaceacbceaabeccd"));
  REQUIRE(Solution().isScramble("abca", "caba"));
  REQUIRE(Solution().isScramble("great", "rgeat"));
  REQUIRE_FALSE(Solution().isScramble("abcde", "caebd"));
  REQUIRE(Solution().isScramble("a", "a"));
}
