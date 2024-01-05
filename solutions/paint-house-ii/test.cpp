#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> costs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .costs{{1, 5, 3}, {2, 9, 4}},
          .expected = 5,
      },
      {
          .costs{{1, 3}, {2, 4}},
          .expected = 5,
      },
  };

  for (const auto &[costs, expected] : test_cases) {
    const auto actual = Solution::minCostII(costs);
    REQUIRE(expected == actual);
  }
}
