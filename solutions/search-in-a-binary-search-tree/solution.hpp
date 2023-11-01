#pragma once

#include <tree_node.h>

/*
  700. Search in a Binary Search Tree
  https://leetcode.com/problems/search-in-a-binary-search-tree/
  Difficulty: Easy
  Tags: Tree, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *searchBST(TreeNode *root, int val) {
    if (!root || root->val == val) {
      return root;
    }

    return val < root->val ? searchBST(root->left, val)
                           : searchBST(root->right, val);
  }
};
