#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int longestCycle(const std::vector<int> &edges) {
    int n = edges.size();
    std::vector<int> in_degree(n, 0);
    for (auto v : edges) {
      if (v != -1) {
        in_degree[v]++;
      }
    }

    std::vector<bool> visited(n, false);
    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (!in_degree[u]) {
        visited[u] = true;
        queue.push(u);
      }
    }
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      const auto v = edges[u];
      if (v != -1 && !--in_degree[v]) {
        visited[v] = true;
        queue.push(v);
      }
    }

    int max_cycle = -1;
    for (int u = 0; u < n; ++u) {
      if (visited[u]) {
        continue;
      }
      visited[u] = true;

      int cycle = 1;
      for (int v = edges[u]; v != -1 && v != u; v = edges[v]) {
        visited[v] = true;
        cycle++;
      }
      if (cycle > 1 && cycle > max_cycle) {
        max_cycle = cycle;
      }
    }
    return max_cycle;
  }
};
