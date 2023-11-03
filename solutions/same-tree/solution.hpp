#pragma once

#include <tree_node.h>

// Time: O(min(N, M))
// Space: O(min(N, M))

class Solution {
public:
  static bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q || p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
