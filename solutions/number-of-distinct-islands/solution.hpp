#pragma once

#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

// Time: O(MN)
// Space: O(MN)

class Solution {
public:
  static int numDistinctIslands(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    std::vector visited(m, std::vector<bool>(n));
    std::unordered_set<std::string> islands;
    std::string island;

    std::function<void(int, int, char)> dfs = [&](int i, int j, char c) {
      if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
      }
      if (!grid[i][j] || visited[i][j]) {
        return;
      }
      visited[i][j] = true;
      island += c;
      dfs(i + 1, j, 'd');
      dfs(i - 1, j, 'u');
      dfs(i, j + 1, 'r');
      dfs(i, j - 1, 'l');
      island += '0';
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        island.clear();
        dfs(i, j, '0');
        if (!island.empty()) {
          islands.insert(island);
        }
      }
    }
    return islands.size();
  }
};
