#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abba", "baba", "bbaa", "cd", "cd"},
          .expected{"abba", "cd"},
      },
      {
          .words{"a", "b", "c", "d", "e"},
          .expected{"a", "b", "c", "d", "e"},
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::removeAnagrams(words);
    REQUIRE(expected == actual);
  }
}
