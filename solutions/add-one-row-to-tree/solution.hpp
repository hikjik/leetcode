#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *addOneRow(TreeNode *root, int val, int depth,
                             bool left = true) {
    if (depth == 1) {
      return left ? new TreeNode(val, root, nullptr)
                  : new TreeNode(val, nullptr, root);
    }
    if (!root) {
      return nullptr;
    }
    root->left = addOneRow(root->left, val, depth - 1, true);
    root->right = addOneRow(root->right, val, depth - 1, false);
    return root;
  }
};
