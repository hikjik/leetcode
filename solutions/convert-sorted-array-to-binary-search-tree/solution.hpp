#pragma once

#include <tree_node.h>

#include <vector>

// Time:
// Space:

class Solution {
public:
  static TreeNode *sortedArrayToBST(const std::vector<int> &nums) {
    return buildTree(0, nums.size() - 1, nums);
  }

private:
  static TreeNode *buildTree(int left, int right,
                             const std::vector<int> &nums) {
    if (left > right) {
      return nullptr;
    }
    const auto middle = left + (right - left) / 2;
    return new TreeNode(nums[middle], buildTree(left, middle - 1, nums),
                        buildTree(middle + 1, right, nums));
  }
};