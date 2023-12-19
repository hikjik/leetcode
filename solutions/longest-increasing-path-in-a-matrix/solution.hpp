#pragma once

#include <queue>
#include <vector>

// Time: O(NM)
// Space: O(NM)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int longestIncreasingPath(const std::vector<std::vector<int>> &mat) {
    const int m = mat.size(), n = mat.back().size();
    std::vector memo(m, std::vector<int>(n));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = std::max(ans, dfs(i, j, INT_MIN, mat, &memo));
      }
    }
    return ans;
  }

private:
  static int dfs(int i, int j, int prev,
                 const std::vector<std::vector<int>> &mat,
                 std::vector<std::vector<int>> *memo) {
    const int m = mat.size(), n = mat.back().size();
    if (i < 0 || i == m || j < 0 || j == n || mat[i][j] <= prev) {
      return 0;
    }

    auto &ans = (*memo)[i][j];
    if (!ans) {
      ans = 1 + std::max({
                    dfs(i + 1, j, mat[i][j], mat, memo),
                    dfs(i - 1, j, mat[i][j], mat, memo),
                    dfs(i, j + 1, mat[i][j], mat, memo),
                    dfs(i, j - 1, mat[i][j], mat, memo),
                });
    }
    return ans;
  }
};

} // namespace memo

namespace topo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int longestIncreasingPath(const std::vector<std::vector<int>> &mat) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = mat.size(), n = mat.back().size();

    std::vector<std::vector<int>> graph(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (const auto &[di, dj] : kDirs) {
          const int r = i + di, c = j + dj;
          if (r >= 0 && r < m && c >= 0 && c < n && mat[i][j] < mat[r][c]) {
            graph[i * n + j].push_back(r * n + c);
          }
        }
      }
    }

    std::vector<int> dp(m * n, 1);
    for (auto u : TopologicalSort(graph)) {
      for (auto v : graph[u]) {
        dp[v] = std::max(dp[v], 1 + dp[u]);
      }
    }
    return std::ranges::max(dp);
  }

private:
  static std::vector<int>
  TopologicalSort(const std::vector<std::vector<int>> &graph) {
    const int n = graph.size();

    std::vector<int> in_degree(n);
    for (int u = 0; u < n; ++u) {
      for (auto v : graph[u]) {
        ++in_degree[v];
      }
    }

    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (!in_degree[u]) {
        queue.push(u);
      }
    }

    std::vector<int> vertices;
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      vertices.push_back(u);
      for (auto v : graph[u]) {
        if (!--in_degree[v]) {
          queue.push(v);
        }
      }
    }

    if (vertices.size() != graph.size()) {
      return {};
    }
    return vertices;
  }
};

} // namespace topo