#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> ans;
    dfs(0, root, &ans);
    return ans;
  }

private:
  static void dfs(int depth, TreeNode *root, std::vector<int> *ans) {
    if (!root)
      return;
    if (depth == std::ssize(*ans)) {
      ans->push_back(root->val);
    }
    dfs(depth + 1, root->right, ans);
    dfs(depth + 1, root->left, ans);
  }
};

} // namespace dfs

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> ans;
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      for (int i = queue.size(); i; --i) {
        auto *node = queue.front();
        queue.pop();

        if (i == 1) {
          ans.push_back(node->val);
        }

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
    }
    return ans;
  }
};

} // namespace bfs
