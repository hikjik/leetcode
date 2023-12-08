#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcabcdabc",
          .expected = 2,
      },
      {
          .s = "aaabaab",
          .expected = 4,
      },
      {
          .s = "aaaaa",
          .expected = 5,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::deleteString(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation Optimized") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = optimized::Solution::deleteString(s);
      REQUIRE(expected == actual);
    }
  }
}
