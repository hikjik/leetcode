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
          .root = {2, 1, 3},
          .expected = 1,
      },
      {
          .root = {1, 2, 3, 4, std::nullopt, 5, 6, std::nullopt, std::nullopt,
                   7},
          .expected = 7,
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::findBottomLeftValue(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::findBottomLeftValue(root);
      REQUIRE(expected == actual);
    }
  }
}
