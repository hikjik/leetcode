#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .edges{{0, 1, 1},
                 {1, 2, 1},
                 {2, 3, 2},
                 {0, 3, 2},
                 {0, 4, 3},
                 {3, 4, 3},
                 {1, 4, 6}},
          .expected{{0, 1}, {2, 3, 4, 5}},
      },
      {
          .n = 4,
          .edges{{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}},
          .expected{{}, {0, 1, 2, 3}},
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::findCriticalAndPseudoCriticalEdges(n, edges);
    REQUIRE(expected == actual);
  }
}
