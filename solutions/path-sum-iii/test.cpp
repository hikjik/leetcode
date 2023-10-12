#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int targetSum;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{10, 5, -3, 3, 2, std::nullopt, 11, 3, -2, std::nullopt, 1},
          .targetSum = 8,
          .expected = 3,
      },
      {
          .root{5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt,
                std::nullopt, 5, 1},
          .targetSum = 22,
          .expected = 3,
      },
  };

  for (const auto &[root, targetSum, expected] : test_cases) {
    const auto actual = Solution::pathSum(root, targetSum);
    REQUIRE(expected == actual);
  }
}
