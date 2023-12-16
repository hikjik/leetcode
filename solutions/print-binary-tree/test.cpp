#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2},
          .expected{{"", "1", ""}, {"2", "", ""}},
      },
      {
          .root = {1, 2, 3, std::nullopt, 4},
          .expected{{"", "", "", "1", "", "", ""},
                    {"", "2", "", "", "", "3", ""},
                    {"", "", "4", "", "", "", ""}},
      },
  };

  SECTION("BFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = bfs::Solution::printTree(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = dfs::Solution::printTree(root);
      REQUIRE(expected == actual);
    }
  }
}
