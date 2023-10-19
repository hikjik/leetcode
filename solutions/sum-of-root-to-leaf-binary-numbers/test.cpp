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
          .root = {1, 0, 1, 0, 1, 0, 1},
          .expected = 22,
      },
      {
          .root = {0},
          .expected = 0,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::sumRootToLeaf(root);
    REQUIRE(expected == actual);
  }
}
