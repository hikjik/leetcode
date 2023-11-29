#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *convertBST(TreeNode *root) {
    convertBST(root, 0);
    return root;
  }

private:
  static int convertBST(TreeNode *root, int val) {
    if (!root) {
      return val;
    }
    root->val += convertBST(root->right, val);
    return convertBST(root->left, root->val);
  }
};
