#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minReorder(int n,
                        const std::vector<std::vector<int>> &connections) {
    std::vector<std::vector<std::pair<int, bool>>> graph(n);
    for (const auto &edge : connections) {
      int u = edge[0], v = edge[1];
      graph[u].emplace_back(v, false);
      graph[v].emplace_back(u, true);
    }
    return dfs(0, -1, graph);
  }

private:
  static int dfs(int u, int parent,
                 const std::vector<std::vector<std::pair<int, bool>>> &graph) {
    int cnt = 0;
    for (const auto &[v, is_reversed] : graph[u]) {
      if (v != parent) {
        cnt += !is_reversed + dfs(v, u, graph);
      }
    }
    return cnt;
  }
};
