#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"},
          .expected = 16,
      },
      {
          .words{"a", "ab", "abc", "d", "cd", "bcd", "abcd"},
          .expected = 4,
      },
      {
          .words{"a", "aa", "aaa", "aaaa"},
          .expected = 0,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::maxProduct(words);
    REQUIRE(expected == actual);
  }
}
