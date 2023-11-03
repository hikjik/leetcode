#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isValidBST(TreeNode *root, TreeNode *min_node = nullptr,
                         TreeNode *max_node = nullptr) {
    if (!root) {
      return true;
    }
    if (min_node && min_node->val >= root->val ||
        max_node && max_node->val <= root->val) {
      return false;
    }
    return isValidBST(root->left, min_node, root) &&
           isValidBST(root->right, root, max_node);
  }
};
