#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    int money;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{1, 2, 2},
          .money = 3,
          .expected = 0,
      },
      {
          .prices{3, 2, 3},
          .money = 3,
          .expected = 3,
      },
  };

  for (const auto &[prices, money, expected] : test_cases) {
    const auto actual = Solution::buyChoco(prices, money);
    REQUIRE(expected == actual);
  }
}
