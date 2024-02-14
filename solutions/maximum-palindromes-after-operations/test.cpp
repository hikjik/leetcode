#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abbb", "ba", "aa"},
          .expected = 3,
      },
      {
          .words{"abc", "ab"},
          .expected = 2,
      },
      {
          .words{"cd", "ef", "a"},
          .expected = 1,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::maxPalindromesAfterOperations(words);
    REQUIRE(expected == actual);
  }
}
