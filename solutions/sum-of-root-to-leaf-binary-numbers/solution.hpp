#pragma once

#include <tree_node.h>

/*
  1022. Sum of Root To Leaf Binary Numbers
  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int sumRootToLeaf(TreeNode *root) { return sumRootToLeaf(0, root); }

private:
  static int sumRootToLeaf(int val, TreeNode *node) {
    if (!node) {
      return 0;
    }

    val = val * 2 + node->val;
    if (!node->left && !node->right) {
      return val;
    }

    return sumRootToLeaf(val, node->left) + sumRootToLeaf(val, node->right);
  }
};
