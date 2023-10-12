#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> coins;
    int amount;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .coins{1, 2, 5},
          .amount = 11,
          .expected = 3,
      },
      {
          .coins{2},
          .amount = 3,
          .expected = -1,
      },
      {
          .coins{1},
          .amount = 0,
          .expected = 0,
      },
  };

  for (const auto &[coins, amount, expected] : test_cases) {
    const auto actual = Solution::coinChange(coins, amount);
    REQUIRE(expected == actual);
  }
}
