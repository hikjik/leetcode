#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"mass", "as", "hero", "superhero"},
          .expected{"as", "hero"},
      },
      {
          .words{"leetcode", "et", "code"},
          .expected{"et", "code"},
      },
      {
          .words{"blue", "green", "bu"},
          .expected{},
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::stringMatching(words);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
