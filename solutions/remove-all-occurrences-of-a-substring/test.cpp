#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string part;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "daabcbaabcbc",
          .part = "abc",
          .expected = "dab",
      },
      {
          .s = "axxxxyyyyb",
          .part = "xy",
          .expected = "ab",
      },
      {
          .s = "abxabb",
          .part = "ab",
          .expected = "xb",
      },
  };

  SECTION("Naive") {
    for (const auto &[s, part, expected] : test_cases) {
      const auto actual = naive::Solution::removeOccurrences(s, part);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[s, part, expected] : test_cases) {
      const auto actual = stack::Solution::removeOccurrences(s, part);
      REQUIRE(expected == actual);
    }
  }

  SECTION("KMP") {
    for (const auto &[s, part, expected] : test_cases) {
      const auto actual = kmp::Solution::removeOccurrences(s, part);
      REQUIRE(expected == actual);
    }
  }
}
