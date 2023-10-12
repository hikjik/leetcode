#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word1;
    std::string word2;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word1 = "abc",
          .word2 = "pqr",
          .expected = "apbqcr",
      },
      {
          .word1 = "ab",
          .word2 = "pqrs",
          .expected = "apbqrs",
      },
      {
          .word1 = "abcd",
          .word2 = "pq",
          .expected = "apbqcd",
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::mergeAlternately(word1, word2);
    REQUIRE(expected == actual);
  }
}
