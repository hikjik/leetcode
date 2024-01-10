#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "*",
          .expected = 9,
      },
      {
          .s = "1*",
          .expected = 18,
      },
      {
          .s = "2*",
          .expected = 15,
      },
      {
          .s = "**",
          .expected = 96,
      },
      {
          .s = "*********",
          .expected = 291868912,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = memo::Solution::numDecodings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::numDecodings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memory Optimized") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = opt::Solution::numDecodings(s);
      REQUIRE(expected == actual);
    }
  }
}
