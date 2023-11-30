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
          .root = {1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4},
          .expected = {2, 1, 3, std::nullopt, std::nullopt, std::nullopt, 4},
      },
      {
          .root = {2, 1, 3},
          .expected = {2, 1, 3},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const Tree actual = Solution::balanceBST(root);
    REQUIRE(actual.IsValidBST());
    REQUIRE(actual.IsBalanced());
    REQUIRE(expected.Traverse(Tree::Order::kInOrder) ==
            actual.Traverse(Tree::Order::kInOrder));
  }
}
