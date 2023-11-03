#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

void checkLongestPalindrome(const std::string &s, const std::string &expected,
                            const std::string &actual) {
  REQUIRE(s.find(actual) != std::string::npos);
  REQUIRE(expected.size() == actual.size());
  REQUIRE(std::equal(actual.begin(), actual.end(), actual.rbegin()));
}

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "babad",
          .expected = "bab",
      },
      {
          .s = "cbbd",
          .expected = "bb",
      },
  };

  SECTION("Dynamic Programming") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::longestPalindrome(s);
      checkLongestPalindrome(s, expected, actual);
    }
  }

  SECTION("Expand From Center") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = optimized::Solution::longestPalindrome(s);
      checkLongestPalindrome(s, expected, actual);
    }
  }

  SECTION("Manacher") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = manacher::Solution::longestPalindrome(s);
      checkLongestPalindrome(s, expected, actual);
    }
  }
}
