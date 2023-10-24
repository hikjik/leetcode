#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = " practice ",
          .expected = "practice  ",
      },
      {
          .text = "  this   is  a sentence ",
          .expected = "this   is   a   sentence",
      },
      {
          .text = " practice   makes   perfect",
          .expected = "practice   makes   perfect ",
      },
  };

  for (const auto &[text, expected] : test_cases) {
    const auto actual = Solution::reorderSpaces(text);
    REQUIRE(expected == actual);
  }
}
