#pragma once

#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> getLonelyNodes(TreeNode *root) {
    std::vector<int> ans;
    dfs(root, &ans);
    return ans;
  }

private:
  static void dfs(TreeNode *root, std::vector<int> *ans) {
    if (!root) {
      return;
    }
    if (!root->left && root->right) {
      ans->push_back(root->right->val);
    }
    if (root->left && !root->right) {
      ans->push_back(root->left->val);
    }
    dfs(root->left, ans);
    dfs(root->right, ans);
  }
};
