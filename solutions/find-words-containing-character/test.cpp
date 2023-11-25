#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    char x;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"leet", "code"},
          .x = 'e',
          .expected{0, 1},
      },
      {
          .words{"abc", "bcd", "aaaa", "cbc"},
          .x = 'a',
          .expected{0, 2},
      },
      {
          .words{"abc", "bcd", "aaaa", "cbc"},
          .x = 'z',
          .expected{},
      },
  };

  for (const auto &[words, x, expected] : test_cases) {
    const auto actual = Solution::findWordsContaining(words, x);
    REQUIRE(expected == actual);
  }
}
