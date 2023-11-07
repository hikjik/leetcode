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
          .root{1, 2, 5, 3, 4, std::nullopt, 6},
          .expected{1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4,
                    std::nullopt, 5, std::nullopt, 6},
      },
      {
          .root{},
          .expected{},
      },
      {
          .root{0},
          .expected{0},
      },
  };

  SECTION("Recursive") {
    for (const auto &[root, expected] : test_cases) {
      TreeNode *copy = Copy(root);
      recursive::Solution::flatten(copy);
      REQUIRE(expected == Tree(copy));
    }
  }

  SECTION("Stack") {
    for (const auto &[root, expected] : test_cases) {
      TreeNode *copy = Copy(root);
      stack::Solution::flatten(copy);
      REQUIRE(expected == Tree(copy));
    }
  }

  SECTION("Iterative") {
    for (const auto &[root, expected] : test_cases) {
      TreeNode *copy = Copy(root);
      iterative::Solution::flatten(copy);
      REQUIRE(expected == Tree(copy));
    }
  }
}
