#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int minimumTime(int n, const std::vector<std::vector<int>> &relations,
                         const std::vector<int> &time) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &relation : relations) {
      graph[relation[0] - 1].push_back(relation[1] - 1);
    }

    auto dp = time;
    for (auto u : TopologicalSort(n, graph)) {
      for (auto v : graph[u]) {
        dp[v] = std::max(dp[v], time[v] + dp[u]);
      }
    }
    return *std::max_element(dp.begin(), dp.end());
  }

private:
  static std::vector<int>
  TopologicalSort(int n, const std::vector<std::vector<int>> &graph) {
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
