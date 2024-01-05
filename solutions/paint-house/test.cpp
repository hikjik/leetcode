#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> costs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .costs{{17, 2, 17}, {16, 16, 5}, {14, 3, 19}},
          .expected = 10,
      },
      {
          .costs{{7, 6, 2}},
          .expected = 2,
      },
  };

  for (const auto &[costs, expected] : test_cases) {
    const auto actual = Solution::minCost(costs);
    REQUIRE(expected == actual);
  }
}
