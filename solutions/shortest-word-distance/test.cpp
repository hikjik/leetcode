#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> wordsDict;
    std::string word1;
    std::string word2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .wordsDict{"practice", "makes", "perfect", "coding", "makes"},
          .word1 = "coding",
          .word2 = "practice",
          .expected = 3,
      },
      {
          .wordsDict{"practice", "makes", "perfect", "coding", "makes"},
          .word1 = "makes",
          .word2 = "coding",
          .expected = 1,
      },
  };

  for (const auto &[wordsDict, word1, word2, expected] : test_cases) {
    const auto actual = Solution::shortestDistance(wordsDict, word1, word2);
    REQUIRE(expected == actual);
  }
}
