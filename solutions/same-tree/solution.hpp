#pragma once

#include <tree_node.h>

/*
  100. Same Tree
  https://leetcode.com/problems/same-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

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
