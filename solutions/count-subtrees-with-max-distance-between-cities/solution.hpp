#pragma once

#include <algorithm>
#include <climits>
#include <vector>

// Time:
// Space:

class Solution {
private:
  // Floyd-Warshall Algorithm
  static std::vector<std::vector<int>>
  computeDistances(int n, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> distances(n, std::vector<int>(n, INT_MAX));
    for (const auto &edge : edges) {
      const auto u = edge[0] - 1, v = edge[1] - 1;
      distances[u][v] = distances[v][u] = 1;
    }

    for (int u = 0; u < n; ++u) {
      distances[u][u] = 0;
    }

    for (int w = 0; w < n; ++w) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          if (distances[u][w] == INT_MAX || distances[w][v] == INT_MAX) {
            continue;
          }

          distances[u][v] =
              std::min(distances[u][v], distances[u][w] + distances[w][v]);
        }
      }
    }

    return distances;
  }

public:
  static std::vector<int>
  countSubgraphsForEachDiameter(int n,
                                const std::vector<std::vector<int>> &edges) {
    const auto distances = computeDistances(n, edges);

    std::vector<int> ans(n - 1, 0);
    for (int mask = 0; mask < 1 << n; ++mask) {

      int edges_count = 0, max_distance = 0;
      for (int u = 0; u < n; ++u) {
        if (!(mask & (1 << u))) {
          continue;
        }

        for (int v = u + 1; v < n; ++v) {
          if (!(mask & (1 << v))) {
            continue;
          }

          edges_count += distances[u][v] == 1;
          max_distance = std::max(max_distance, distances[u][v]);
        }
      }

      const auto vertex_count = __builtin_popcount(mask);
      if (edges_count + 1 == vertex_count && max_distance) {
        ++ans[max_distance - 1];
      }
    }

    return ans;
  }
};
