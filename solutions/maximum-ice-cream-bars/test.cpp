#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> costs;
    int coins;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .costs{1, 3, 2, 4, 1},
          .coins = 7,
          .expected = 4,
      },
      {
          .costs{10, 6, 8, 7, 7, 8},
          .coins = 5,
          .expected = 0,
      },
      {
          .costs{1, 6, 3, 1, 2, 5},
          .coins = 20,
          .expected = 6,
      },
  };

  for (const auto &[costs, coins, expected] : test_cases) {
    const auto actual = Solution::maxIceCream(costs, coins);
    REQUIRE(expected == actual);
  }
}
