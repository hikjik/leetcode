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
          .root{1, 2, 3, 4, 5},
          .expected = 3,
      },
      {
          .root{1, 2},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::diameterOfBinaryTree(root);
    REQUIRE(expected == actual);
  }
}
