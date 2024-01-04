#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string keyboard;
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .keyboard = "abcdefghijklmnopqrstuvwxyz",
          .word = "cba",
          .expected = 4,
      },
      {
          .keyboard = "pqrstuvwxyzabcdefghijklmno",
          .word = "leetcode",
          .expected = 73,
      },
  };

  for (const auto &[keyboard, word, expected] : test_cases) {
    const auto actual = Solution::calculateTime(keyboard, word);
    REQUIRE(expected == actual);
  }
}
