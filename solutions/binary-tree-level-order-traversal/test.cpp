#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected{{3}, {9, 20}, {15, 7}},
      },
      {
          .root{1},
          .expected{{1}},
      },
      {
          .root{},
          .expected{},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::levelOrder(root);
    REQUIRE(expected == actual);
  }
}
