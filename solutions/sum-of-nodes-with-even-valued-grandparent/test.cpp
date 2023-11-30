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
          .root = {6, 7, 8, 2, 7, 1, 3, 9, std::nullopt, 1, 4, std::nullopt,
                   std::nullopt, std::nullopt, 5},
          .expected = 18,
      },
      {
          .root = {1},
          .expected = 0,
      },
  };

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::sumEvenGrandparent(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::sumEvenGrandparent(root);
      REQUIRE(expected == actual);
    }
  }
}
