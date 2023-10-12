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
          .root{1, 2, 3},
          .expected = 6,
      },
      {
          .root{-10, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected = 42,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::maxPathSum(root);
    REQUIRE(expected == actual);
  }
}
