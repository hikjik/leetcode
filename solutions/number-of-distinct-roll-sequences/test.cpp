#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = 22,
      },
      {
          .n = 4,
          .expected = 184,
      },
  };

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::distinctSequences(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::distinctSequences(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = optimized::Solution::distinctSequences(n);
      REQUIRE(expected == actual);
    }
  }
}
