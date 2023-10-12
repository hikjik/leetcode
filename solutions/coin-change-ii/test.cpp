#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int amount;
    std::vector<int> coins;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .amount = 5,
          .coins{1, 2, 5},
          .expected = 4,
      },
      {
          .amount = 3,
          .coins{2},
          .expected = 0,
      },
      {
          .amount = 10,
          .coins{10},
          .expected = 1,
      },
  };

  for (const auto &[amount, coins, expected] : test_cases) {
    const auto actual = Solution::change(amount, coins);
    REQUIRE(expected == actual);
  }
}
