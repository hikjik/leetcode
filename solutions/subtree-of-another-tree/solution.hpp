#pragma once

#include <tree_node.h>

/*
  572. Subtree of Another Tree
  https://leetcode.com/problems/subtree-of-another-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
  Time:
  Space:
*/

class Solution {
public:
  static bool isSubtree(TreeNode *root, TreeNode *sub_root) {
    return root &&
           (equalTree(root, sub_root) || isSubtree(root->left, sub_root) ||
            isSubtree(root->right, sub_root));
  }

private:
  static bool equalTree(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) {
      return true;
    }
    if (!root1 || !root2 || root1->val != root2->val) {
      return false;
    }
    return equalTree(root1->left, root2->left) &&
           equalTree(root1->right, root2->right);
  }
};
