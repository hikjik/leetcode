#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  findMinHeightTrees(int n, const std::vector<std::vector<int>> &edges) {
    if (n == 1) {
      return {0};
    }

    std::vector<int> degree(n);
    std::vector<std::vector<int>> adj(n);
    for (const auto &edge : edges) {
      const auto u = edge[0], v = edge[1];
      ++degree[u], ++degree[v];
      adj[u].push_back(v), adj[v].push_back(u);
    }

    std::vector<int> nodes;
    for (int u = 0; u < n; ++u) {
      if (degree[u] == 1) {
        nodes.push_back(u);
      }
    }

    while (n > 2) {
      n -= nodes.size();
      std::vector<int> next;
      for (auto u : nodes) {
        for (auto v : adj[u]) {
          if (--degree[v] == 1) {
            next.push_back(v);
          }
        }
      }
      nodes.swap(next);
    }
    return nodes;
  }
};
