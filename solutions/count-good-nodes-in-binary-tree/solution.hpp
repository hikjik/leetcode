#pragma once

#include <tree_node.h>

#include <climits>

/*
  1448. Count Good Nodes in Binary Tree
  https://leetcode.com/problems/count-good-nodes-in-binary-tree/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int goodNodes(TreeNode *root) { return dfs(INT_MIN, root); }

private:
  static int dfs(int max, TreeNode *node) {
    if (!node) {
      return 0;
    }
    int good = node->val >= max;
    max = std::max(max, node->val);
    return good + dfs(max, node->left) + dfs(max, node->right);
  }
};
