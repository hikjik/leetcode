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
          .edges{{1, 0}, {1, 2}, {1, 3}},
          .expected{1},
      },
      {
          .n = 6,
          .edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}},
          .expected{3, 4},
      },
      {
          .n = 1,
          .edges{},
          .expected{0},
      },
      {
          .n = 3,
          .edges{{0, 1}, {0, 2}},
          .expected{0},
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::findMinHeightTrees(n, edges);
    REQUIRE(expected == actual);
  }
}
