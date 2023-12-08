#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "level",
          .expected = "l",
      },
      {
          .s = "ababab",
          .expected = "abab",
      },
  };

  SECTION("KMP") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = kmp::Solution::longestPrefix(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Rolling Hash") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = hash::Solution::longestPrefix(s);
      REQUIRE(expected == actual);
    }
  }
}
