#pragma once

#include <tree_node.h>

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    return getLeafs(root1) == getLeafs(root2);
  }

private:
  static std::vector<int> getLeafs(TreeNode *root) {
    std::vector<int> leafs;
    dfs(root, &leafs);
    return leafs;
  }

  static void dfs(TreeNode *node, std::vector<int> *leafs) {
    if (!node) {
      return;
    }
    if (!node->left && !node->right) {
      leafs->push_back(node->val);
      return;
    }
    dfs(node->left, leafs);
    dfs(node->right, leafs);
  }
};
