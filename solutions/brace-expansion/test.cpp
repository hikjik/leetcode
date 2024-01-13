#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "{a,b}c{d,e}f",
          .expected{"acdf", "acef", "bcdf", "bcef"},
      },
      {
          .s = "abcd",
          .expected{"abcd"},
      },
      {
          .s = "{a,b}cd{d,e}fkk",
          .expected{"acddfkk", "acdefkk", "bcddfkk", "bcdefkk"},
      },
  };

  SECTION("Iterative") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = iterative::Solution::expand(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Recursive") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = recursive::Solution::expand(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Backtracking") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = backtracking::Solution::expand(s);
      REQUIRE(expected == actual);
    }
  }
}
