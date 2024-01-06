#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}},
          .expected = true,
      },
      {
          .n = 5,
          .edges{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}},
          .expected = false,
      },
  };

  SECTION("DFS") {
    for (const auto &[n, edges, expected] : test_cases) {
      const auto actual = dfs::Solution::validTree(n, edges);
      REQUIRE(expected == actual);
    }
  }

  SECTION("BFS") {
    for (const auto &[n, edges, expected] : test_cases) {
      const auto actual = bfs::Solution::validTree(n, edges);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Union Find") {
    for (const auto &[n, edges, expected] : test_cases) {
      const auto actual = uf::Solution::validTree(n, edges);
      REQUIRE(expected == actual);
    }
  }
}
