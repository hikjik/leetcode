#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcdcbaecba",
          .expected = "abceabcdcbaecba",
      },
      {
          .s = "aacecaaa",
          .expected = "aaacecaaa",
      },
      {
          .s = "abcd",
          .expected = "dcbabcd",
      },
      {
          .s = "abcba",
          .expected = "abcba",
      },
  };

  SECTION("Brute Force") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = brute_force::Solution::shortestPalindrome(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Recursive") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = recursive::Solution::shortestPalindrome(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Rolling Hash") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = rolling_hash::Solution::shortestPalindrome(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("KMP") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = kmp::Solution::shortestPalindrome(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Manacher") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = manacher::Solution::shortestPalindrome(s);
      REQUIRE(expected == actual);
    }
  }
}
