#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static bool
  possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
    std::vector<std::vector<int>> graph(n + 1);
    for (const auto &edge : dislikes) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector<int> colors(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
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
          if (colors[v] == 0) {
            colors[v] = -colors[u];
            queue.push(v);
          }
        }
      }
    }
    return true;
  }
};
