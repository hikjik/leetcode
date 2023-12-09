#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int target;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2, 3, 2, std::nullopt, 2, 4},
          .target = 2,
          .expected = {1, std::nullopt, 3, std::nullopt, 4},
      },
      {
          .root = {1, 3, 3, 3, 2},
          .target = 3,
          .expected = {1, 3, std::nullopt, std::nullopt, 2},
      },
      {
          .root = {1, 2, std::nullopt, 2, std::nullopt, 2},
          .target = 2,
          .expected = {1},
      },
      {
          .root = {1, 1, 1},
          .target = 1,
          .expected = {},
      },
  };

  for (const auto &[root, target, expected] : test_cases) {
    const Tree actual = Solution::removeLeafNodes(Copy(root), target);
    REQUIRE(expected == actual);
  }
}
