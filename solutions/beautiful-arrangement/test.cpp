#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 1,
      },
      {
          .n = 2,
          .expected = 2,
      },
      {
          .n = 3,
          .expected = 3,
      },
      {
          .n = 15,
          .expected = 24679,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::countArrangement(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::countArrangement(n);
      REQUIRE(expected == actual);
    }
  }
}
