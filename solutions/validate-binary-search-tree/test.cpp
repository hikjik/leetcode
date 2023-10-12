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
          .root{2, 1, 3},
          .expected = true,
      },
      {
          .root{5, 1, 4, std::nullopt, std::nullopt, 3, 6},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isValidBST(root);
    REQUIRE(expected == actual);
  }
}
