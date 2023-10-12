#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int k;
    std::vector<int> prices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .k = 2,
          .prices{2, 4, 1},
          .expected = 2,
      },
      {
          .k = 2,
          .prices{3, 2, 6, 5, 0, 3},
          .expected = 7,
      },
  };

  for (const auto &[k, prices, expected] : test_cases) {
    const auto actual = Solution::maxProfit(k, prices);
    REQUIRE(expected == actual);
  }
}
