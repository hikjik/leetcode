#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 1, 1, 1, 1, std::nullopt, 1},
          .expected = true,
      },
      {
          .root = {2, 2, 2, 5, 2},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isUnivalTree(root);
    REQUIRE(expected == actual);
  }
}
