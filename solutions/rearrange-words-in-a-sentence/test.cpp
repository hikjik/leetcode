#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = "Leetcode is cool",
          .expected = "Is cool leetcode",
      },
      {
          .text = "Keep calm and code on",
          .expected = "On and keep calm code",
      },
      {
          .text = "To be or not to be",
          .expected = "To be or to be not",
      },
  };

  for (const auto &[text, expected] : test_cases) {
    const auto actual = Solution::arrangeWords(text);
    REQUIRE(expected == actual);
  }
}
