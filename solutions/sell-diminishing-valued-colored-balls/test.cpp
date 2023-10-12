#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> inventory;
    int orders;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .inventory{2, 5},
          .orders = 4,
          .expected = 14,
      },
      {
          .inventory{3, 5},
          .orders = 6,
          .expected = 19,
      },
  };

  for (const auto &[inventory, orders, expected] : test_cases) {
    const auto actual = Solution::maxProfit(inventory, orders);
    REQUIRE(expected == actual);
  }
}
