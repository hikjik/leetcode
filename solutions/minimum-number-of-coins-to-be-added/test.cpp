#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> coins;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .coins{65},
          .target = 100,
          .expected = 7,
      },
      {
          .coins{},
          .target = 100,
          .expected = 7,
      },
      {
          .coins{1, 4, 10},
          .target = 19,
          .expected = 2,
      },
      {
          .coins{1, 4, 10, 5, 7, 19},
          .target = 19,
          .expected = 1,
      },
      {
          .coins{1, 1, 1},
          .target = 20,
          .expected = 3,
      },
      {
          .coins{2},
          .target = 5,
          .expected = 2,
      },
  };

  for (const auto &[coins, target, expected] : test_cases) {
    const auto actual = Solution::minimumAddedCoins(coins, target);
    REQUIRE(expected == actual);
  }
}
