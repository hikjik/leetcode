#pragma once

#include <tree_node.h>

/*
  617. Merge Two Binary Trees
  https://leetcode.com/problems/merge-two-binary-trees/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) {
      return nullptr;
    }

    int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
    auto left = mergeTrees(root1 ? root1->left : nullptr,
                           root2 ? root2->left : nullptr);
    auto right = mergeTrees(root1 ? root1->right : nullptr,
                            root2 ? root2->right : nullptr);

    return new TreeNode(val, left, right);
  }
};
