#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2, 3, 4, 5, std::nullopt, 6, 7, std::nullopt,
                   std::nullopt, std::nullopt, std::nullopt, 8},
          .expected = 15,
      },
      {
          .root = {15},
          .expected = 15,
      },
      {
          .root = {6, 7, 8, 2, 7, 1, 3, 9, std::nullopt, 1, 4, std::nullopt,
                   std::nullopt, std::nullopt, 5},
          .expected = 19,
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::deepestLeavesSum(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::deepestLeavesSum(root);
      REQUIRE(expected == actual);
    }
  }
}
