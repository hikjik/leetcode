#pragma once

#include <tree_node.h>

/*
  965. Univalued Binary Tree
  https://leetcode.com/problems/univalued-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool isUnivalTree(TreeNode *root) {
    if (!root) {
      return true;
    }

    for (auto child : {root->left, root->right}) {
      if (child && root->val != child->val) {
        return false;
      }
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
  }
};
