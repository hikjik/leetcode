#pragma once

#include <tree_node.h>

#include <vector>

/*
  94. Binary Tree Inorder Traversal
  https://leetcode.com/problems/binary-tree-inorder-traversal/
  Difficulty: Easy
  Tags: Stack, Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInOrder(root, &values);
    return values;
  }

private:
  static void traverseInOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    traverseInOrder(root->left, values);
    values->push_back(root->val);
    traverseInOrder(root->right, values);
  }
};
