#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"lc", "cl", "gg"},
          .expected = 6,
      },
      {
          .words{"ab", "ty", "yt", "lc", "cl", "ab"},
          .expected = 8,
      },
      {
          .words{"cc", "ll", "xx"},
          .expected = 2,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::longestPalindrome(words);
    REQUIRE(expected == actual);
  }
}
