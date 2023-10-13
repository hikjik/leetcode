#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2, 3, std::nullopt, 5},
          .expected{"1->2->5", "1->3"},
      },
      {
          .root = {1},
          .expected{"1"},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::binaryTreePaths(root);
    REQUIRE(expected == actual);
  }
}
