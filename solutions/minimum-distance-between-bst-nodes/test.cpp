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
          .root{4, 2, 6, 1, 3},
          .expected = 1,
      },
      {
          .root{1, 0, 48, std::nullopt, std::nullopt, 12, 49},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::minDiffInBST(root);
    REQUIRE(expected == actual);
  }
}
