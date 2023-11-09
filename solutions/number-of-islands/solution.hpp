#pragma once

#include <queue>
#include <vector>

// Time: O(NM)
// Space: O(NM)

namespace dfs {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int numIslands(std::vector<std::vector<char>> grid) {
    int ans = 0;
    for (int i = 0; i < std::ssize(grid); ++i) {
      for (int j = 0; j < std::ssize(grid[0]); ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          dfs(i, j, grid);
        }
      }
    }
    return ans;
  }

private:
  static void dfs(int i, int j, std::vector<std::vector<char>> &grid) {
    if (i < 0 || i >= std::ssize(grid) || j < 0 || j >= std::ssize(grid[0])) {
      return;
    }
    if (grid[i][j] != '1') {
      return;
    }

    grid[i][j] = '0';
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
  }
};

} // namespace dfs

namespace bfs {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int numIslands(std::vector<std::vector<char>> grid) {
    int ans = 0;
    for (int i = 0; i < std::ssize(grid); ++i) {
      for (int j = 0; j < std::ssize(grid[0]); ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          bfs(i, j, grid);
        }
      }
    }
    return ans;
  }

private:
  static void bfs(int i, int j, std::vector<std::vector<char>> &grid) {
    static const std::vector<std::pair<int, int>> dirs{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    const int n = grid.size(), m = grid.back().size();

    std::queue<std::pair<int, int>> queue;
    queue.emplace(i, j);
    grid[i][j] = '0';
    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      for (const auto &[di, dj] : dirs) {
        const int r = i + di, c = j + dj;
        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1') {
          queue.emplace(r, c);
          grid[r][c] = '0';
        }
      }
    }
  }
};

} // namespace bfs
