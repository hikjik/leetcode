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
          .root = {1, std::nullopt, 2, 3, 4},
          .expected{1, 3, 4, 2},
      },
      {
          .root = {1, 2, 3, 4, 5, 6, std::nullopt, std::nullopt, std::nullopt,
                   7, 8, 9, 10},
          .expected{1, 2, 4, 7, 8, 9, 10, 6, 3},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::boundaryOfBinaryTree(root);
    REQUIRE(expected == actual);
  }
}
