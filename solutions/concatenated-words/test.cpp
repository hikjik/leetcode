#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"cat", "cats", "catsdogcats", "dog", "dogcatsdog",
                 "hippopotamuses", "rat", "ratcatdogcat"},
          .expected{"catsdogcats", "dogcatsdog", "ratcatdogcat"},
      },
      {
          .words{"cat", "dog", "catdog"},
          .expected{"catdog"},
      },
  };

  SECTION("Tabulation") {
    for (const auto &[words, expected] : test_cases) {
      const auto actual = dp::Solution::findAllConcatenatedWordsInADict(words);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Memoization") {
    for (const auto &[words, expected] : test_cases) {
      const auto actual =
          memo::Solution::findAllConcatenatedWordsInADict(words);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }
}
