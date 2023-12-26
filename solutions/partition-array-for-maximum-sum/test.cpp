#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 15, 7, 9, 2, 5, 10},
          .k = 3,
          .expected = 84,
      },
      {
          .arr{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3},
          .k = 4,
          .expected = 83,
      },
      {
          .arr{1},
          .k = 1,
          .expected = 1,
      },
  };

  SECTION("Memoization") {
    for (const auto &[arr, k, expected] : test_cases) {
      const auto actual = memo::Solution::maxSumAfterPartitioning(arr, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[arr, k, expected] : test_cases) {
      const auto actual = dp::Solution::maxSumAfterPartitioning(arr, k);
      REQUIRE(expected == actual);
    }
  }
}
