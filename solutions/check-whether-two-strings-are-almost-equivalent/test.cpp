#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word1;
    std::string word2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word1 = "aaaa",
          .word2 = "bccb",
          .expected = false,
      },
      {
          .word1 = "abcdeef",
          .word2 = "abaaacc",
          .expected = true,
      },
      {
          .word1 = "cccddabba",
          .word2 = "babababab",
          .expected = true,
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::checkAlmostEquivalent(word1, word2);
    REQUIRE(expected == actual);
  }
}
