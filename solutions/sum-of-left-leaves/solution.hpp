#pragma once

#include <tree_node.h>

/*
  404. Sum of Left Leaves
  https://leetcode.com/problems/sum-of-left-leaves/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    sumOfLeftLeaves(root, &sum);
    return sum;
  }

private:
  static void sumOfLeftLeaves(TreeNode *root, int *sum) {
    if (!root) {
      return;
    }

    if (isLeaf(root->left)) {
      *sum += root->left->val;
    }

    sumOfLeftLeaves(root->left, sum);
    sumOfLeftLeaves(root->right, sum);
  }

  static bool isLeaf(TreeNode *node) {
    return node && !node->left && !node->right;
  }
};
