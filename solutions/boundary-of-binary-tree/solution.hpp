#pragma once

#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> boundaryOfBinaryTree(TreeNode *root) {
    std::vector<int> ans{root->val};
    dfs(root->left, true, false, &ans);
    dfs(root->right, false, true, &ans);
    return ans;
  }

private:
  static void dfs(TreeNode *node, bool lb, bool rb, std::vector<int> *ans) {
    if (!node) {
      return;
    }
    if (lb || isLeaf(node)) {
      ans->push_back(node->val);
    }
    dfs(node->left, lb, rb && !node->right, ans);
    dfs(node->right, lb && !node->left, rb, ans);
    if (rb && !isLeaf(node)) {
      ans->push_back(node->val);
    }
  }

  static bool isLeaf(TreeNode *node) {
    return node && !node->left && !node->right;
  }
};
