#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int minTime(int n, const std::vector<std::vector<int>> &edges,
                     const std::vector<bool> &hasApple) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    return dfs(0, -1, graph, hasApple);
  }

private:
  static int dfs(int u, int p, const std::vector<std::vector<int>> &graph,
                 const std::vector<bool> &hasApple) {
    int totalTime = 0;
    for (auto v : graph[u]) {
      if (v != p) {
        const auto time = dfs(v, u, graph, hasApple);
        if (time || hasApple[v]) {
          totalTime += time + 2;
        }
      }
    }
    return totalTime;
  }
};
