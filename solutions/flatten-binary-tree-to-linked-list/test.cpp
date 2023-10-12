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

  for (const auto &[root, expected] : test_cases) {
    TreeNode *copy = Copy(root);
    Solution::flatten(copy);
    REQUIRE(expected == Tree(copy));
  }
}
