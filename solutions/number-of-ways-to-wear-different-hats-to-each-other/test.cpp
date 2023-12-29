#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> hats;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .hats{{3, 4}, {4, 5}, {5}},
          .expected = 1,
      },
      {
          .hats{{3, 5, 1}, {3, 5}},
          .expected = 4,
      },
      {
          .hats{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
          .expected = 24,
      },
  };

  SECTION("Memoization") {
    for (const auto &[hats, expected] : test_cases) {
      const auto actual = memo::Solution::numberWays(hats);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[hats, expected] : test_cases) {
      const auto actual = dp::Solution::numberWays(hats);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[hats, expected] : test_cases) {
      const auto actual = optimized::Solution::numberWays(hats);
      REQUIRE(expected == actual);
    }
  }
}
