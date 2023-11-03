#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string beginWord;
    std::string endWord;
    std::vector<std::string> wordList;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .beginWord = "hit",
          .endWord = "cog",
          .wordList{"hot", "dot", "dog", "lot", "log", "cog"},
          .expected{{"hit", "hot", "dot", "dog", "cog"},
                    {"hit", "hot", "lot", "log", "cog"}},
      },
      {
          .beginWord = "hit",
          .endWord = "cog",
          .wordList{"hot", "dot", "dog", "lot", "log"},
          .expected{},
      },
  };

  for (const auto &[beginWord, endWord, wordList, expected] : test_cases) {
    const auto actual = Solution::findLadders(beginWord, endWord, wordList);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
