#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int minProfit;
    std::vector<int> group;
    std::vector<int> profit;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .minProfit = 3,
          .group{2, 2},
          .profit{2, 3},
          .expected = 2,
      },
      {
          .n = 10,
          .minProfit = 5,
          .group{2, 3, 5},
          .profit{6, 7, 8},
          .expected = 7,
      },
  };

  for (const auto &[n, minProfit, group, profit, expected] : test_cases) {
    const auto actual =
        Solution::profitableSchemes(n, minProfit, group, profit);
    REQUIRE(expected == actual);
  }
}
