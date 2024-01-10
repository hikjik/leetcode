#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> houses;
    std::vector<std::vector<int>> cost;
    int m;
    int n;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .houses{0, 0, 0, 0, 0},
          .cost{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}},
          .m = 5,
          .n = 2,
          .target = 3,
          .expected = 9,
      },
      {
          .houses{0, 2, 1, 2, 0},
          .cost{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}},
          .m = 5,
          .n = 2,
          .target = 3,
          .expected = 11,
      },
      {
          .houses{3, 1, 2, 3},
          .cost{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
          .m = 4,
          .n = 3,
          .target = 3,
          .expected = -1,
      },
  };

  SECTION("Memoization") {
    for (const auto &[houses, cost, m, n, target, expected] : test_cases) {
      const auto actual = memo::Solution::minCost(houses, cost, m, n, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[houses, cost, m, n, target, expected] : test_cases) {
      const auto actual = dp::Solution::minCost(houses, cost, m, n, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[houses, cost, m, n, target, expected] : test_cases) {
      const auto actual = opt::Solution::minCost(houses, cost, m, n, target);
      REQUIRE(expected == actual);
    }
  }
}
