#pragma once

#include <functional>
#include <vector>

// Time: O(V+E)
// Space: O(V+E)
// Notes: [Tarjan's Bridge Algo](https://w.wiki/8mUU)

class Solution {
public:
  static std::vector<std::vector<int>>
  criticalConnections(int n, const std::vector<std::vector<int>> &connections) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : connections) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    int clock = 0;
    std::vector<int> disc(n), low(n);
    std::vector<std::vector<int>> bridges;

    std::function<void(int, int)> dfs = [&](int u, int p) {
      disc[u] = low[u] = ++clock;
      for (auto v : graph[u]) {
        if (v == p) {
          continue;
        }

        if (!disc[v]) {
          dfs(v, u);
          if (disc[u] < low[v]) {
            bridges.push_back({u, v});
          }
          low[u] = std::min(low[u], low[v]);
        } else {
          low[u] = std::min(low[u], disc[v]);
        }
      }
    };

    dfs(0, -1);
    return bridges;
  }
};
