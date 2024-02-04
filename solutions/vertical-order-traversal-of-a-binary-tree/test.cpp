#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {3, 1, 4, 0, 2, 2},
          .expected{{0}, {1}, {3, 2, 2}, {4}},
      },
      {
          .root = {3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected{{9}, {3, 15}, {20}, {7}},
      },
      {
          .root = {1, 2, 3, 4, 5, 6, 7},
          .expected{{4}, {2}, {1, 5, 6}, {3}, {7}},
      },
      {
          .root = {1, 2, 3, 4, 6, 5, 7},
          .expected{{4}, {2}, {1, 5, 6}, {3}, {7}},
      },
  };

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::verticalTraversal(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::verticalTraversal(root);
      REQUIRE(expected == actual);
    }
  }
}
