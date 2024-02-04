#pragma once

#include <functional>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

#include <tree_node.h>

// Time: O(NlogN)
// Space: O(N)

namespace dfs {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>> verticalTraversal(TreeNode *root) {
    std::map<int, std::vector<std::pair<int, int>>> map;

    std::function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int x,
                                                        int y) {
      if (!node) {
        return;
      }
      map[x].push_back({y, node->val});
      dfs(node->left, x - 1, y + 1);
      dfs(node->right, x + 1, y + 1);
    };

    dfs(root, 0, 0);
    std::vector<std::vector<int>> ans;
    for (auto &[_, group] : map) {
      std::ranges::sort(group);
      std::vector<int> vals;
      for (const auto &[_, val] : group) {
        vals.push_back(val);
      }
      ans.push_back(std::move(vals));
    }
    return ans;
  }
};

} // namespace dfs

namespace bfs {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>> verticalTraversal(TreeNode *root) {
    std::vector<std::vector<int>> vals;
    std::queue<std::tuple<TreeNode *, int, int>> queue{{{root, 0, 0}}};
    while (!queue.empty()) {
      const auto [node, x, y] = queue.front();
      queue.pop();

      vals.push_back({x, y, node->val});
      if (node->left) {
        queue.push({node->left, x - 1, y + 1});
      }
      if (node->right) {
        queue.push({node->right, x + 1, y + 1});
      }
    }

    std::ranges::sort(vals);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < std::ssize(vals); ++i) {
      if (!i || vals[i - 1][0] != vals[i][0]) {
        ans.emplace_back();
      }
      ans.back().push_back(vals[i][2]);
    }
    return ans;
  }
};

} // namespace bfs
