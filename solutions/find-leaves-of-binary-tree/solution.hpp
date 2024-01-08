#pragma once

#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> findLeaves(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    findLeaves(root, &ans);
    return ans;
  }

private:
  static size_t findLeaves(TreeNode *node, std::vector<std::vector<int>> *ans) {
    if (!node) {
      return 0;
    }
    const auto height =
        1 + std::max(findLeaves(node->left, ans), findLeaves(node->right, ans));
    if (ans->size() < height) {
      ans->emplace_back();
    }
    (*ans)[height - 1].push_back(node->val);
    return height;
  }
};
