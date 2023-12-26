#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .k = 6,
          .target = 3,
          .expected = 1,
      },
      {
          .n = 2,
          .k = 6,
          .target = 7,
          .expected = 6,
      },
      {
          .n = 30,
          .k = 30,
          .target = 500,
          .expected = 222616187,
      },
  };

  SECTION("Memoization") {
    for (const auto &[n, k, target, expected] : test_cases) {
      const auto actual = memo::Solution::numRollsToTarget(n, k, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[n, k, target, expected] : test_cases) {
      const auto actual = dp::Solution::numRollsToTarget(n, k, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("optimized") {
    for (const auto &[n, k, target, expected] : test_cases) {
      const auto actual = dp::Solution::numRollsToTarget(n, k, target);
      REQUIRE(expected == actual);
    }
  }
}
