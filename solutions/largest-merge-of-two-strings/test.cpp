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
          .word1 = "cabaa",
          .word2 = "bcaaa",
          .expected = "cbcabaaaaa",
      },
      {
          .word1 = "abcabc",
          .word2 = "abdcaba",
          .expected = "abdcabcabcaba",
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::largestMerge(word1, word2);
    REQUIRE(expected == actual);
  }
}
