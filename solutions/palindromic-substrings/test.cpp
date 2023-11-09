#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abbabas",
          .expected = 11,
      },
      {
          .s = "abc",
          .expected = 3,
      },
      {
          .s = "aaa",
          .expected = 6,
      },
  };

  SECTION("Manacher Algorithm") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = manacher::Solution::countSubstrings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = memo::Solution::countSubstrings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::countSubstrings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Expand From Center") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = expand::Solution::countSubstrings(s);
      REQUIRE(expected == actual);
    }
  }
}
