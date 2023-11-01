#pragma once

#include <tree_node.h>

/*
  236. Lowest Common Ancestor of a Binary Tree
  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

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
