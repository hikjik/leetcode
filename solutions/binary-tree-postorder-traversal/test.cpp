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
          .expected{3, 2, 1},
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

  SECTION("Recursive") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = recursive::Solution::postorderTraversal(root);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[root, expected] : test_cases) {
      const auto actual = iterative::Solution::postorderTraversal(root);
      REQUIRE(expected == actual);
    }
  }
}
