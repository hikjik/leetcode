#pragma once

#include <tree_node.h>

/*
  701. Insert into a Binary Search Tree
  https://leetcode.com/problems/insert-into-a-binary-search-tree/
  Difficulty: Medium
  Tags: Tree, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};
