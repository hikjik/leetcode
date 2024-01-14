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
          .root = {5, 1, 5, 5, 5, std::nullopt, 5},
          .expected = 4,
      },
      {
          .root = {},
          .expected = 0,
      },
      {
          .root = {5, 5, 5, 5, 5, std::nullopt, 5},
          .expected = 6,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::countUnivalSubtrees(root);
    REQUIRE(expected == actual);
  }
}
