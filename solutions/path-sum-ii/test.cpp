#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int targetSum;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt,
                std::nullopt, 5, 1},
          .targetSum = 22,
          .expected{{5, 4, 11, 2}, {5, 8, 4, 5}},
      },
      {
          .root{1, 2, 3},
          .targetSum = 5,
          .expected{},
      },
      {
          .root{1, 2},
          .targetSum = 0,
          .expected{},
      },
  };

  for (const auto &[root, targetSum, expected] : test_cases) {
    const auto actual = Solution::pathSum(root, targetSum);
    REQUIRE(expected == actual);
  }
}
