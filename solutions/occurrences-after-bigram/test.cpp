#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    std::string first;
    std::string second;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = "alice is a good girl she is a good student",
          .first = "a",
          .second = "good",
          .expected{"girl", "student"},
      },
      {
          .text = "we will we will rock you",
          .first = "we",
          .second = "will",
          .expected{"we", "rock"},
      },
  };

  for (const auto &[text, first, second, expected] : test_cases) {
    const auto actual = Solution::findOcurrences(text, first, second);
    REQUIRE(expected == actual);
  }
}
