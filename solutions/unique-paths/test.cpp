#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 3,
          .n = 7,
          .expected = 28,
      },
      {
          .m = 3,
          .n = 2,
          .expected = 3,
      },
  };

  SECTION("Memoization") {
    for (const auto &[m, n, expected] : test_cases) {
      const auto actual = memo::Solution::uniquePaths(m, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DP") {
    for (const auto &[m, n, expected] : test_cases) {
      const auto actual = dp::Solution::uniquePaths(m, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memory Optimized") {
    for (const auto &[m, n, expected] : test_cases) {
      const auto actual = optimized::Solution::uniquePaths(m, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Combinatorics") {
    for (const auto &[m, n, expected] : test_cases) {
      const auto actual = combinatorics::Solution::uniquePaths(m, n);
      REQUIRE(expected == actual);
    }
  }
}
