#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &nums) {
  auto root = Solution::sortedArrayToBST(nums);

  REQUIRE(isValidBST(root));
  REQUIRE(isBalanced(root));
  REQUIRE(nums == TraverseInOrder(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums{-10, -3, 0, 5, 9};
    CheckSolution(nums);
  }
  {
    std::vector<int> nums{1, 2, 3};
    CheckSolution(nums);
  }
  {
    std::vector<int> nums{1, 2};
    CheckSolution(nums);
  }
  {
    std::vector<int> nums{1};
    CheckSolution(nums);
  }
  {
    std::vector<int> nums;
    CheckSolution(nums);
  }
}
