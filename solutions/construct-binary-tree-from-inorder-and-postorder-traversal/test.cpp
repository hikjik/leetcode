#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> inorder;
    std::vector<int> postorder;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .inorder{9, 3, 15, 20, 7},
          .postorder{9, 15, 7, 20, 3},
          .expected{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
      },
      {
          .inorder{-1},
          .postorder{-1},
          .expected{-1},
      },
  };

  for (const auto &[inorder, postorder, expected] : test_cases) {
    const Tree actual = Solution::buildTree(inorder, postorder);
    REQUIRE(expected == actual);
  }
}
