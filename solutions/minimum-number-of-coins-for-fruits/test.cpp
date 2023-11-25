#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{3, 1, 2},
          .expected = 4,
      },
      {
          .prices{1, 10, 1, 1},
          .expected = 2,
      },
  };

  SECTION("Memoization") {
    for (const auto &[prices, expected] : test_cases) {
      const auto actual = memo::Solution::minimumCoins(prices);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[prices, expected] : test_cases) {
      const auto actual = dp::Solution::minimumCoins(prices);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Track Minimum") {
    for (const auto &[prices, expected] : test_cases) {
      const auto actual = track_minimum::Solution::minimumCoins(prices);
      REQUIRE(expected == actual);
    }
  }
}
