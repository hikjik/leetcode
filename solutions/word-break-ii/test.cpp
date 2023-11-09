#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> wordList;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "catsanddog",
          .wordList{"cat", "cats", "and", "sand", "dog"},
          .expected{"cats and dog", "cat sand dog"},
      },
      {
          .s = "pineapplepenapple",
          .wordList{"apple", "pen", "applepen", "pine", "pineapple"},
          .expected{"pine apple pen apple", "pineapple pen apple",
                    "pine applepen apple"},
      },
      {
          .s = "catsandog",
          .wordList{"cats", "dog", "sand", "and", "cat"},
          .expected{},
      },
  };

  SECTION("Backtracking") {
    for (const auto &[s, wordList, expected] : test_cases) {
      const auto actual = backtracking::Solution::wordBreak(s, wordList);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Memoization") {
    for (const auto &[s, wordList, expected] : test_cases) {
      const auto actual = memo::Solution::wordBreak(s, wordList);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, wordList, expected] : test_cases) {
      const auto actual = dp::Solution::wordBreak(s, wordList);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }
}
