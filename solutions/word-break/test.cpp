#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> wordDict;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetcode",
          .wordDict{"leet", "code"},
          .expected = true,
      },
      {
          .s = "applepenapple",
          .wordDict{"apple", "pen"},
          .expected = true,
      },
      {
          .s = "catsandog",
          .wordDict{"cats", "dog", "sand", "and", "cat"},
          .expected = false,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, wordDict, expected] : test_cases) {
      const auto actual = memo::Solution::wordBreak(s, wordDict);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, wordDict, expected] : test_cases) {
      const auto actual = dp::Solution::wordBreak(s, wordDict);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[s, wordDict, expected] : test_cases) {
      const auto actual = optimized::Solution::wordBreak(s, wordDict);
      REQUIRE(expected == actual);
    }
  }
}
