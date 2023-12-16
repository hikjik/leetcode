#pragma once

#include <queue>
#include <string>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<std::string>> printTree(TreeNode *root) {
    const auto height = getDepth(root) - 1;
    const int m = height + 1, n = (1 << m) - 1;

    std::vector ans(m, std::vector<std::string>(n));
    std::queue<std::pair<TreeNode *, int>> queue{{{root, (n - 1) / 2}}};
    for (int r = 0; !queue.empty(); ++r) {
      for (int sz = queue.size(); sz; --sz) {
        const auto [node, c] = queue.front();
        queue.pop();

        ans[r][c] = std::to_string(node->val);

        if (node->left) {
          queue.push({node->left, c - (1 << (height - r - 1))});
        }
        if (node->right) {
          queue.push({node->right, c + (1 << (height - r - 1))});
        }
      }
    }
    return ans;
  }

private:
  static int getDepth(TreeNode *node) {
    if (!node) {
      return 0;
    }
    return 1 + std::max(getDepth(node->left), getDepth(node->right));
  }
};

} // namespace bfs

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<std::string>> printTree(TreeNode *root) {
    const auto height = getDepth(root) - 1;
    const int m = height + 1, n = (1 << m) - 1;
    std::vector ans(m, std::vector<std::string>(n));
    printTree(root, 0, (n - 1) / 2, height, &ans);
    return ans;
  }

private:
  static void printTree(TreeNode *node, int r, int c, int h,
                        std::vector<std::vector<std::string>> *ans) {
    (*ans)[r][c] = std::to_string(node->val);
    if (node->left) {
      printTree(node->left, r + 1, c - (1 << (h - r - 1)), h, ans);
    }
    if (node->right) {
      printTree(node->right, r + 1, c + (1 << (h - r - 1)), h, ans);
    }
  }

  static int getDepth(TreeNode *node) {
    if (!node) {
      return 0;
    }
    return 1 + std::max(getDepth(node->left), getDepth(node->right));
  }
};

} // namespace dfs
