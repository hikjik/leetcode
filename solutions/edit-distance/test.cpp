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
          .word1 = "horse",
          .word2 = "ros",
          .expected = 3,
      },
      {
          .word1 = "intention",
          .word2 = "execution",
          .expected = 5,
      },
  };

  SECTION("Memoization") {
    for (const auto &[word1, word2, expected] : test_cases) {
      const auto actual = memo::Solution::minDistance(word1, word2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Bottom-Up") {
    for (const auto &[word1, word2, expected] : test_cases) {
      const auto actual = dp::Solution::minDistance(word1, word2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memory Optimized") {
    for (const auto &[word1, word2, expected] : test_cases) {
      const auto actual = optimized::Solution::minDistance(word1, word2);
      REQUIRE(expected == actual);
    }
  }
}
