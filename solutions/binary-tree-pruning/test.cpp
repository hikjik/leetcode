#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, std::nullopt, 0, 0, 1},
          .expected = {1, std::nullopt, 0, std::nullopt, 1},
      },
      {
          .root = {1, 0, 1, 0, 0, 0, 1},
          .expected = {1, std::nullopt, 1, std::nullopt, 1},
      },
      {
          .root = {1, 1, 0, 1, 1, 0, 1, 0},
          .expected = {1, 1, 0, 1, 1, std::nullopt, 1},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const Tree actual = Solution::pruneTree(Copy(root));
    REQUIRE(expected == actual);
  }
}
