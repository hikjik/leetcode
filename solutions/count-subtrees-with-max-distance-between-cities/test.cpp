#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .edges{{1, 2}, {2, 3}, {2, 4}},
          .expected{3, 4, 0},
      },
      {
          .n = 2,
          .edges{{1, 2}},
          .expected{1},
      },
      {
          .n = 3,
          .edges{{1, 2}, {2, 3}},
          .expected{2, 1},
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::countSubgraphsForEachDiameter(n, edges);
    REQUIRE(expected == actual);
  }
}
