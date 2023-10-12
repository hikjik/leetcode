#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "(()",
          .expected = 2,
      },
      {
          .s = ")()())",
          .expected = 4,
      },
      {
          .s = "",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::longestValidParentheses(s);
    REQUIRE(expected == actual);
  }
}
