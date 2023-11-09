#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 2, 3, std::nullopt, 5, std::nullopt, 4},
          .expected{1, 3, 4},
      },
      {
          .root{1, std::nullopt, 3},
          .expected{1, 3},
      },
      {
          .root{},
          .expected{},
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::rightSideView(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::rightSideView(root);
      REQUIRE(expected == actual);
    }
  }
}
