#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int shortestPathLength(const std::vector<std::vector<int>> &graph) {
    const int n = graph.size();
    int mask = (1 << n) - 1;

    std::queue<std::tuple<int, int, int>> queue;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(1 << n, false));

    for (int u = 0; u < n; ++u) {
      int u_mask = 1 << u;
      queue.emplace(u, u_mask, 0);
      visited[u][u_mask] = true;
    }

    while (!queue.empty()) {
      const auto [u, u_mask, distance] = queue.front();
      queue.pop();

      if (u_mask == mask) {
        return distance;
      }

      for (auto v : graph[u]) {
        const int v_mask = (u_mask | (1 << v));
        if (!visited[v][v_mask]) {
          queue.emplace(v, v_mask, distance + 1);
          visited[v][v_mask] = true;
        }
      }
    }
    return 0;
  }
};
