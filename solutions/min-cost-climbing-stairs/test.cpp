#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> cost;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .cost{10, 15, 20},
          .expected = 15,
      },
      {
          .cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1},
          .expected = 6,
      },
  };

  for (const auto &[cost, expected] : test_cases) {
    const auto actual = Solution::minCostClimbingStairs(cost);
    REQUIRE(expected == actual);
  }
}
