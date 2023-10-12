#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> tokens;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tokens{"2", "1", "+", "3", "*"},
          .expected = 9,
      },
      {
          .tokens{"4", "13", "5", "/", "+"},
          .expected = 6,
      },
      {
          .tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+",
                  "5", "+"},
          .expected = 22,
      },
  };

  for (const auto &[tokens, expected] : test_cases) {
    const auto actual = Solution::evalRPN(tokens);
    REQUIRE(expected == actual);
  }
}
