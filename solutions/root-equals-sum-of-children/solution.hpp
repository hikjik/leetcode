#pragma once

#include <tree_node.h>

class Solution {
public:
  static bool checkTree(TreeNode *root) {
    return root->val == root->left->val + root->right->val;
  }
};
