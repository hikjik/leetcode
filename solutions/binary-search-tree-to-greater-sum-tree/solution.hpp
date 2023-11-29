#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *bstToGst(TreeNode *root) {
    bstToGst(root, 0);
    return root;
  }

private:
  static int bstToGst(TreeNode *root, int val) {
    if (!root) {
      return val;
    }
    root->val += bstToGst(root->right, val);
    return bstToGst(root->left, root->val);
  }
};
