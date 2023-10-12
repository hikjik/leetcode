#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string beginWord;
    std::string endWord;
    std::vector<std::string> wordList;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .beginWord = "hit",
          .endWord = "cog",
          .wordList{"hot", "dot", "dog", "lot", "log", "cog"},
          .expected = 5,
      },
      {
          .beginWord = "hit",
          .endWord = "cog",
          .wordList{"hot", "dot", "dog", "lot", "log"},
          .expected = 0,
      },
  };

  for (const auto &[beginWord, endWord, wordList, expected] : test_cases) {
    const auto actual = Solution::ladderLength(beginWord, endWord, wordList);
    REQUIRE(expected == actual);
  }
}
