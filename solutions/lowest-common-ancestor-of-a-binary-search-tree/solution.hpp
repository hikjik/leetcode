#pragma once

#include <tree_node.h>

/*
  235. Lowest Common Ancestor of a Binary Search Tree
  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                        TreeNode *q) {
    if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};