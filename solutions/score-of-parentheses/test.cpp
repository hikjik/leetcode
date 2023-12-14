#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "()",
          .expected = 1,
      },
      {
          .s = "(())",
          .expected = 2,
      },
      {
          .s = "()()",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::scoreOfParentheses(s);
    REQUIRE(expected == actual);
  }
}
