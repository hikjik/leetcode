#pragma once

#include <vector>

// M = max(coins)
// Time: O(NlogM)
// Space: O(N)

class Solution {
public:
  static int maximumPoints(const std::vector<std::vector<int>> &edges,
                           const std::vector<int> &coins, int k) {
    const int n = edges.size() + 1;
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector memo(n, std::vector<int>(14, -1));
    return dfs(0, -1, 0, graph, coins, k, &memo);
  }

  static int dfs(int u, int p, int s,
                 const std::vector<std::vector<int>> &graph,
                 const std::vector<int> &coins, int k,
                 std::vector<std::vector<int>> *memo) {
    if (s == 14) {
      return 0;
    }
    auto &ans = (*memo)[u][s];
    if (ans != -1) {
      return ans;
    }

    int way1 = (coins[u] >> s) - k;
    int way2 = (coins[u] >> (s + 1));
    for (auto v : graph[u]) {
      if (v != p) {
        way1 += dfs(v, u, s, graph, coins, k, memo);
        way2 += dfs(v, u, s + 1, graph, coins, k, memo);
      }
    }
    return ans = std::max(way1, way2);
  }
};
