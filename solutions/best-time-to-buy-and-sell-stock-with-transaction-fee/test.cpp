#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    int fee;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{1, 3, 2, 8, 4, 9},
          .fee = 2,
          .expected = 8,
      },
      {
          .prices{1, 3, 7, 5, 10, 3},
          .fee = 3,
          .expected = 6,
      },
  };

  for (const auto &[prices, fee, expected] : test_cases) {
    const auto actual = Solution::maxProfit(prices, fee);
    REQUIRE(expected == actual);
  }
}
