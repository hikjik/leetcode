#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{1, 2, 3, 0, 2},
          .expected = 3,
      },
      {
          .prices{1},
          .expected = 0,
      },
  };

  for (const auto &[prices, expected] : test_cases) {
    const auto actual = Solution::maxProfit(prices);
    REQUIRE(expected == actual);
  }
}
