#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static long long
  maximumScoreAfterOperations(const std::vector<std::vector<int>> &edges,
                              const std::vector<int> &values) {
    std::vector<std::vector<int>> graph(edges.size() + 1);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    return std::reduce(values.begin(), values.end(), 0LL) -
           dfs(0, -1, graph, values);
  }

private:
  static long long dfs(int u, int p, const std::vector<std::vector<int>> &graph,
                       const std::vector<int> &values) {
    if (isLeaf(u, graph)) {
      return values[u];
    }

    long long sum = 0;
    for (int v : graph[u]) {
      if (v != p) {
        sum += dfs(v, u, graph, values);
      }
    }
    return std::min<long long>(sum, values[u]);
  }

  static bool isLeaf(int u, const std::vector<std::vector<int>> &graph) {
    return u > 0 && graph[u].size() == 1;
  }
};
