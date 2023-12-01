#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string pattern;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abc", "deq", "mee", "aqq", "dkd", "ccc"},
          .pattern = "abb",
          .expected{"mee", "aqq"},
      },
      {
          .words{"a", "b", "c"},
          .pattern = "a",
          .expected{"a", "b", "c"},
      },
  };

  for (const auto &[words, pattern, expected] : test_cases) {
    const auto actual = Solution::findAndReplacePattern(words, pattern);
    REQUIRE(expected == actual);
  }
}
