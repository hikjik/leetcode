#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string digits;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .digits = "23",
          .expected{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"},
      },
      {
          .digits = "",
          .expected{},
      },
      {
          .digits = "2",
          .expected{"a", "b", "c"},
      },
  };

  SECTION("Backtracking") {
    for (const auto &[digits, expected] : test_cases) {
      const auto actual = backtracking::Solution::letterCombinations(digits);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[digits, expected] : test_cases) {
      const auto actual = iterative::Solution::letterCombinations(digits);
      REQUIRE(expected == actual);
    }
  }
}
