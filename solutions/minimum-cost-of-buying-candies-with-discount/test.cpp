#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> cost;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .cost{10, 5, 9, 4, 1, 9, 10, 2, 10, 8},
          .expected = 48,
      },
      {
          .cost{1, 2, 3},
          .expected = 5,
      },
      {
          .cost{6, 5, 7, 9, 2, 2},
          .expected = 23,
      },
      {
          .cost{5, 5},
          .expected = 10,
      },
  };

  for (const auto &[cost, expected] : test_cases) {
    const auto actual = Solution::minimumCost(cost);
    REQUIRE(expected == actual);
  }
}
