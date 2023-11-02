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
          .root = {4, 8, 5, 0, 1, std::nullopt, 6},
          .expected = 5,
      },
      {
          .root = {1},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::averageOfSubtree(root);
    REQUIRE(expected == actual);
  }
}
