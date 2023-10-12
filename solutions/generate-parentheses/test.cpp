#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected{"((()))", "(()())", "(())()", "()(())", "()()()"},
      },
      {
          .n = 1,
          .expected{"()"},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::generateParenthesis(n);
    REQUIRE(expected == actual);
  }
}
