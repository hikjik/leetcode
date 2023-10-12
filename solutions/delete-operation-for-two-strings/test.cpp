#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word1;
    std::string word2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word1 = "sea",
          .word2 = "eat",
          .expected = 2,
      },
      {
          .word1 = "leetcode",
          .word2 = "etco",
          .expected = 4,
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::minDistance(word1, word2);
    REQUIRE(expected == actual);
  }
}
