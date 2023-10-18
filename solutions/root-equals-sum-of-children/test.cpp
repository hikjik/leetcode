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
          .root = {10, 4, 6},
          .expected = true,
      },
      {
          .root = {5, 3, 1},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::checkTree(root);
    REQUIRE(expected == actual);
  }
}
