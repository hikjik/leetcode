#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string p;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aa",
          .p = "a",
          .expected = false,
      },
      {
          .s = "aa",
          .p = "a*",
          .expected = true,
      },
      {
          .s = "ab",
          .p = ".*",
          .expected = true,
      },
      {
          .s = "mississippi",
          .p = "mis*is*p*.",
          .expected = false,
      },
  };

  SECTION("Regex") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = regex::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Recursion") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = recursion::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = memo::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = dp::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memory Optimized") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = optimized::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }
}
