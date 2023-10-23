#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> prices;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .prices{8, 4, 6, 2, 3},
          .expected{4, 2, 4, 2, 3},
      },
      {
          .prices{1, 2, 3, 4, 5},
          .expected{1, 2, 3, 4, 5},
      },
      {
          .prices{10, 1, 1, 6},
          .expected{9, 0, 1, 6},
      },
  };

  for (const auto &[prices, expected] : test_cases) {
    const auto actual = Solution::finalPrices(prices);
    REQUIRE(expected == actual);
  }
}
