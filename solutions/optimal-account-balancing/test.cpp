#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> transactions;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .transactions{{0, 1, 10}, {2, 0, 5}},
          .expected = 2,
      },
      {
          .transactions{{0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}},
          .expected = 1,
      },
  };

  SECTION("Backtracking") {
    for (const auto &[transactions, expected] : test_cases) {
      const auto actual = backtracing::Solution::minTransfers(transactions);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[transactions, expected] : test_cases) {
      const auto actual = memo::Solution::minTransfers(transactions);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[transactions, expected] : test_cases) {
      const auto actual = dp::Solution::minTransfers(transactions);
      REQUIRE(expected == actual);
    }
  }
}
