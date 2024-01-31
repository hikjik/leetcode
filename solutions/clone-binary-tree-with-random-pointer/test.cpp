#include <catch.hpp>

#include <solution.hpp>

#include <tree_node_with_random.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{{1, std::nullopt}, {}, {4, 3}, {7, 0}},
          .expected{{1, std::nullopt}, {}, {4, 3}, {7, 0}},
      },
      {
          .root{{1, 4}, {}, {1, 0}, {}, {1, 5}, {1, 5}},
          .expected{{1, 4}, {}, {1, 0}, {}, {1, 5}, {1, 5}},
      },
      {
          .root{{1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}, {7, 0}},
          .expected{{1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}, {7, 0}},
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = bfs::Solution::copyRandomBinaryTree(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = dfs::Solution::copyRandomBinaryTree(root);
      REQUIRE(expected == actual);
    }
  }
}
