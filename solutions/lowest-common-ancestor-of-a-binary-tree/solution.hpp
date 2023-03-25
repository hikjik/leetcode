#pragma once

#include <tree_node.h>

class Solution {
public:
  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                        TreeNode *q) {
    if (!root || root == p || root == q) {
      return root;
    }

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    return l && r ? root : l ? l : r;
  }
};
