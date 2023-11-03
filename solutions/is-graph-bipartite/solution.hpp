#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool isBipartite(const std::vector<std::vector<int>> &graph) {
    int n = graph.size();
    std::vector<int> colors(n, 0);

    for (int u = 0; u < n; ++u) {
      if (colors[u]) {
        continue;
      }

      colors[u] = 1;

      std::queue<int> queue;
      queue.push(u);

      while (!queue.empty()) {
        const auto u = queue.front();
        queue.pop();

        for (auto v : graph[u]) {
          if (colors[v] == colors[u]) {
            return false;
          }
          if (!colors[v]) {
            colors[v] = -colors[u];
            queue.push(v);
          }
        }
      }
    }
    return true;
  }
};
