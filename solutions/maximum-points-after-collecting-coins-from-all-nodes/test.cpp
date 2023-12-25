#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    std::vector<int> coins;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{0, 1}, {1, 2}, {2, 3}},
          .coins{10, 10, 3, 3},
          .k = 5,
          .expected = 11,
      },
      {
          .edges{{0, 1}, {0, 2}},
          .coins{8, 4, 4},
          .k = 0,
          .expected = 16,
      },
  };

  for (const auto &[edges, coins, k, expected] : test_cases) {
    const auto actual = Solution::maximumPoints(edges, coins, k);
    REQUIRE(expected == actual);
  }
}
