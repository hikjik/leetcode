#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> preorder;
    std::vector<int> inorder;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .preorder{3, 9, 20, 15, 7},
          .inorder{9, 3, 15, 20, 7},
          .expected{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
      },
      {
          .preorder{-1},
          .inorder{-1},
          .expected{-1},
      },
  };

  for (const auto &[preorder, inorder, expected] : test_cases) {
    const Tree actual = Solution::buildTree(preorder, inorder);
    REQUIRE(expected == actual);
  }
}
