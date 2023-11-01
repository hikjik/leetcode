#pragma once

#include <tree_node.h>

#include <vector>

/*
  108. Convert Sorted Array to Binary Search Tree
  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
  Difficulty: Easy
  Tags: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

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