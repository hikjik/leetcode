#pragma once

#include <tree_node.h>

/*
  2265. Count Nodes Equal to Average of Subtree
  https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Binary Tree
  Time: O(N)
  Space: O(N)
*/

class Solution {
public:
  static int averageOfSubtree(TreeNode *root) {
    int ans = 0;
    traversePostOrder(root, &ans);
    return ans;
  }

private:
  static std::pair<int, int> traversePostOrder(TreeNode *node, int *ans) {
    if (!node) {
      return {0, 0};
    }
    const auto [left_sum, left_count] = traversePostOrder(node->left, ans);
    const auto [right_sum, right_count] = traversePostOrder(node->right, ans);
    const auto sum = left_sum + right_sum + node->val;
    const auto count = left_count + right_count + 1;
    if (node->val == sum / count) {
      ++*ans;
    }
    return {sum, count};
  }
};
