#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int targetSum;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt,
                std::nullopt, std::nullopt, 1},
          .targetSum = 22,
          .expected = true,
      },
      {
          .root{1, 2, 3},
          .targetSum = 5,
          .expected = false,
      },
      {
          .root{},
          .targetSum = 0,
          .expected = false,
      },
  };

  for (const auto &[root, targetSum, expected] : test_cases) {
    const auto actual = Solution::hasPathSum(root, targetSum);
    REQUIRE(expected == actual);
  }
}
