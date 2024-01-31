#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<int> vals;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .vals{4, 7},
          .expected = 2,
      },
      {
          .root = {3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .vals{1},
          .expected = 1,
      },
      {
          .root = {3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .vals{7, 6, 2, 4},
          .expected = 5,
      },
  };

  for (const auto &[root, vals, expected] : test_cases) {
    std::vector<TreeNode *> nodes;
    for (auto val : vals) {
      nodes.push_back(root.Find(val));
    }

    const auto actual = Solution::lowestCommonAncestor(root, nodes);
    REQUIRE(actual != nullptr);
    REQUIRE(expected == actual->val);
  }
}
