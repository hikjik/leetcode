#pragma once

#include <tree_node.h>

#include <algorithm>
#include <limits>
#include <optional>

/*
  530. Minimum Absolute Difference in BST
  https://leetcode.com/problems/minimum-absolute-difference-in-bst/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree,
        Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int getMinimumDifference(TreeNode *root) {
    int diff = std::numeric_limits<int>::max();
    std::optional<int> previous = std::nullopt;
    inOrderTraversal(root, diff, previous);
    return diff;
  }

private:
  static void inOrderTraversal(TreeNode *root, int &diff,
                               std::optional<int> &previous) {
    if (!root) {
      return;
    }

    inOrderTraversal(root->left, diff, previous);
    if (previous) {
      diff = std::min(diff, root->val - previous.value());
    }
    previous = root->val;
    inOrderTraversal(root->right, diff, previous);
  }
};
