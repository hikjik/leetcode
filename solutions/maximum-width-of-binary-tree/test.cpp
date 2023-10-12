#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 3, 2, 5, 3, std::nullopt, 9},
          .expected = 4,
      },
      {
          .root{1, 3, 2, 5, std::nullopt, std::nullopt, 9, 6, std::nullopt, 7},
          .expected = 7,
      },
      {
          .root{1, 3, 2, 5},
          .expected = 2,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::widthOfBinaryTree(root);
    REQUIRE(expected == actual);
  }
}
