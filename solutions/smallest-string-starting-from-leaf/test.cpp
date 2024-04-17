#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {0, 1, 2, 3, 4, 3, 4},
          .expected = "dba",
      },
      {
          .root = {25, 1, 3, 1, 3, 0, 2},
          .expected = "adz",
      },
      {
          .root = {2, 2, 1, std::nullopt, 1, 0, std::nullopt, 0},
          .expected = "abc",
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::smallestFromLeaf(root);
    REQUIRE(expected == actual);
  }
}
