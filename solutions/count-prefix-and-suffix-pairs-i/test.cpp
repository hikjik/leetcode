#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"a", "aba", "ababa", "aa"},
          .expected = 4,
      },
      {
          .words{"pa", "papa", "ma", "mama"},
          .expected = 2,
      },
      {
          .words{"abab", "ab"},
          .expected = 0,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::countPrefixSuffixPairs(words);
    REQUIRE(expected == actual);
  }
}
