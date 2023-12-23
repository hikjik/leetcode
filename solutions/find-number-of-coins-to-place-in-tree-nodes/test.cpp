#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    std::vector<int> cost;
    std::vector<long long> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}},
          .cost{1, 2, 3, 4, 5, 6},
          .expected{120, 1, 1, 1, 1, 1},
      },
      {
          .edges{
              {0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {2, 8}},
          .cost{1, 4, 2, 3, 5, 7, 8, -4, 2},
          .expected{280, 140, 32, 1, 1, 1, 1, 1, 1},
      },
      {
          .edges{{0, 1}, {0, 2}},
          .cost{1, 2, -2},
          .expected{0, 1, 1},
      },
  };

  for (const auto &[edges, cost, expected] : test_cases) {
    const auto actual = Solution::placedCoins(edges, cost);
    REQUIRE(expected == actual);
  }
}
