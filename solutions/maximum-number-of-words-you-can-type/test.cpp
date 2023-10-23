#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    std::string brokenLetters;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = "hello world",
          .brokenLetters = "ad",
          .expected = 1,
      },
      {
          .text = "leet code",
          .brokenLetters = "lt",
          .expected = 1,
      },
      {
          .text = "leet code",
          .brokenLetters = "e",
          .expected = 0,
      },
  };

  for (const auto &[text, brokenLetters, expected] : test_cases) {
    const auto actual = Solution::canBeTypedWords(text, brokenLetters);
    REQUIRE(expected == actual);
  }
}
