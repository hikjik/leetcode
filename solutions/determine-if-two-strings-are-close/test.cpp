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
          .word1 = "abc",
          .word2 = "bca",
          .expected = true,
      },
      {
          .word1 = "a",
          .word2 = "aa",
          .expected = false,
      },
      {
          .word1 = "cabbba",
          .word2 = "abbccc",
          .expected = true,
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::closeStrings(word1, word2);
    REQUIRE(expected == actual);
  }
}
