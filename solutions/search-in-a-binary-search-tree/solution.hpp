#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static TreeNode *searchBST(TreeNode *root, int val) {
    if (!root || root->val == val) {
      return root;
    }

    return val < root->val ? searchBST(root->left, val)
                           : searchBST(root->right, val);
  }
};
