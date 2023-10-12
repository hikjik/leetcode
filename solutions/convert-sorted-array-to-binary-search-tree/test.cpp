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
          .nums{-10, -3, 0, 5, 9},
          .expected{0, -3, 9, -10, std::nullopt, 5},
      },
      {
          .nums{1, 3},
          .expected{3, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const Tree actual = Solution::sortedArrayToBST(nums);

    REQUIRE(actual.IsValidBST());
    REQUIRE(actual.IsBalanced());
    REQUIRE(expected.Traverse(Tree::Order::kInOrder) ==
            actual.Traverse(Tree::Order::kInOrder));
  }
}
