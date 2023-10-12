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
          .root{1, std::nullopt, 2, 3},
          .expected{1, 2, 3},
      },
      {
          .root{},
          .expected{},
      },
      {
          .root{1},
          .expected{1},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::preorderTraversal(root);
    REQUIRE(expected == actual);
  }
}
