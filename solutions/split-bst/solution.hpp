#pragma once

#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<TreeNode *> splitBST(TreeNode *root, int target) {
    if (!root) {
      return {nullptr, nullptr};
    }
    if (root->val <= target) {
      const auto trees = splitBST(root->right, target);
      root->right = trees[0];
      return {root, trees[1]};
    }
    const auto trees = splitBST(root->left, target);
    root->left = trees[1];
    return {trees[0], root};
  }
};
