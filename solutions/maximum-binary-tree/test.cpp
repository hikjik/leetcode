#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 1, 6, 0, 5},
          .expected = {6, 3, 5, std::nullopt, 2, 0, std::nullopt, std::nullopt,
                       1},
      },
      {
          .nums{3, 2, 1},
          .expected = {3, std::nullopt, 2, std::nullopt, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const Tree actual = Solution::constructMaximumBinaryTree(nums);
    REQUIRE(expected == actual);
  }
}
