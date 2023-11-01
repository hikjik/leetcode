#pragma once

#include <tree_node.h>

#include <unordered_set>

/*
  653. Two Sum IV - Input is a BST
  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
  Difficulty: Easy
  Tags: Hash Table, Two Pointers, Tree, Depth-First Search,
        Breadth-First Search, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool findTarget(TreeNode *root, int target) {
    std::unordered_set<int> seen;
    return traverseInOrder(root, target, &seen);
  }

private:
  static bool traverseInOrder(TreeNode *node, int target,
                              std::unordered_set<int> *seen) {
    if (!node) {
      return false;
    }

    if (traverseInOrder(node->left, target, seen) || seen->count(node->val)) {
      return true;
    }
    seen->insert(target - node->val);
    return traverseInOrder(node->right, target, seen);
  }
};
