#pragma once

#include <tree_node.h>

class Solution {
public:
  static bool isValidBST(TreeNode *root) {
    return isValidBST(root, nullptr, nullptr);
  }

private:
  static bool isValidBST(TreeNode *root, TreeNode *min_node,
                         TreeNode *max_node) {
    if (!root) {
      return true;
    }
    if ((min_node && min_node->val >= root->val) ||
        (max_node && root->val >= max_node->val)) {
      return false;
    }

    return isValidBST(root->left, min_node, root) &&
           isValidBST(root->right, root, max_node);
  }
};
