#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> words{"lc", "cl", "gg"};
    REQUIRE(6 == Solution::longestPalindrome(words));
  }
  {
    std::vector<std::string> words{"ab", "ty", "yt", "lc", "cl", "ab"};
    REQUIRE(8 == Solution::longestPalindrome(words));
  }
  {
    std::vector<std::string> words{"cc", "ll", "xx"};
    REQUIRE(2 == Solution::longestPalindrome(words));
  }
  {
    std::vector<std::string> words{"dd", "aa", "bb", "dd", "aa", "dd", "bb",
                                   "dd", "aa", "cc", "bb", "cc", "dd", "cc"};
    REQUIRE(22 == Solution::longestPalindrome(words));
  }
}
