#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{7, 1, 5, 3, 6, 4},
          .expected = 7,
      },
      {
          .prices{1, 2, 3, 4, 5},
          .expected = 4,
      },
      {
          .prices{7, 6, 4, 3, 1},
          .expected = 0,
      },
  };

  for (const auto &[prices, expected] : test_cases) {
    const auto actual = Solution::maxProfit(prices);
    REQUIRE(expected == actual);
  }
}
