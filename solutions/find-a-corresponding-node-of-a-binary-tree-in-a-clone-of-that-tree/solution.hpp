#pragma once

#include <tree_node.h>

/*
  1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
  https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                                 TreeNode *target) {
    if (!original) {
      return nullptr;
    }
    if (original == target) {
      return cloned;
    }
    if (auto left = getTargetCopy(original->left, cloned->left, target); left) {
      return left;
    }
    return getTargetCopy(original->right, cloned->right, target);
  }
};
