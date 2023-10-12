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
          .root{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected = true,
      },
      {
          .root{1, 2, 2, 3, 3, std::nullopt, std::nullopt, 4, 4},
          .expected = false,
      },
      {
          .root{},
          .expected = true,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isBalanced(root);
    REQUIRE(expected == actual);
  }
}
