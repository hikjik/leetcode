#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> redEdges;
    std::vector<std::vector<int>> blueEdges;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .redEdges{{0, 1}, {1, 2}},
          .blueEdges{},
          .expected{0, 1, -1},
      },
      {
          .n = 3,
          .redEdges{{0, 1}},
          .blueEdges{{2, 1}},
          .expected{0, 1, -1},
      },
  };

  for (const auto &[n, redEdges, blueEdges, expected] : test_cases) {
    const auto actual =
        Solution::shortestAlternatingPaths(n, redEdges, blueEdges);
    REQUIRE(expected == actual);
  }
}
