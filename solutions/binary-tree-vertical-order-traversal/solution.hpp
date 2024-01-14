#pragma once

#include <climits>
#include <queue>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> verticalOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    int min = INT_MAX, max = INT_MIN;
    dfs(root, 0, &min, &max);

    std::vector<std::vector<int>> ans(max - min + 1);
    std::queue<std::pair<TreeNode *, int>> queue{{{root, 0}}};
    while (!queue.empty()) {
      const auto [node, i] = queue.front();
      queue.pop();

      ans[i - min].push_back(node->val);

      if (node->left) {
        queue.push({node->left, i - 1});
      }
      if (node->right) {
        queue.push({node->right, i + 1});
      }
    }
    return ans;
  }

private:
  static void dfs(TreeNode *node, int i, int *min, int *max) {
    if (!node) {
      return;
    }
    *min = std::min(*min, i);
    *max = std::max(*max, i);
    dfs(node->left, i - 1, min, max);
    dfs(node->right, i + 1, min, max);
  }
};
