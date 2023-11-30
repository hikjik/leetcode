#pragma once

#include <stack>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *balanceBST(TreeNode *root) {
    const auto order = traverseInorder(root);
    return buildTree(0, order.size() - 1, order);
  }

private:
  // 94. Binary Tree Inorder Traversal
  // https://leetcode.com/problems/binary-tree-inorder-traversal/
  static std::vector<int> traverseInorder(TreeNode *root) {
    std::vector<int> values;
    std::stack<TreeNode *> stack;

    auto *node = root;
    while (node || !stack.empty()) {
      while (node) {
        stack.push(node);
        node = node->left;
      }
      node = stack.top();
      stack.pop();
      values.push_back(node->val);
      node = node->right;
    }
    return values;
  }

  // 108. Convert Sorted Array to Binary Search Tree
  // https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
