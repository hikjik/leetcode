#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val);
    }
    if (root->val < val) {
      return new TreeNode(val, root, nullptr);
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};
