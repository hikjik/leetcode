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

  SECTION("Brute Force") {
    for (auto &[n, expected] : test_cases) {
      const auto actual = brute_force::Solution::generateParenthesis(n);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Backtracing") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = backtracking::Solution::generateParenthesis(n);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Dynamic Programming") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::generateParenthesis(n);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }
}
