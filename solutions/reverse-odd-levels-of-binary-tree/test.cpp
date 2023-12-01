#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {2, 3, 5, 8, 13, 21, 34},
          .expected = {2, 5, 3, 8, 13, 21, 34},
      },
      {
          .root = {7, 13, 11},
          .expected = {7, 11, 13},
      },
      {
          .root = {0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2},
          .expected = {0, 2, 1, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1},
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = bfs::Solution::reverseOddLevels(Copy(root));
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = dfs::Solution::reverseOddLevels(Copy(root));
      REQUIRE(expected == actual);
    }
  }
}
