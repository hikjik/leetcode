#pragma once

#include <vector>

// Time: O(2^NN^3)
// Space: O(N^2)
// Notes: [Floyd–Warshall](https://w.wiki/4xCV)

class Solution {
public:
  static int numberOfSets(int n, int maxDistance,
                          const std::vector<std::vector<int>> &roads) {
    int ans = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
      ans += numberOfSets(n, maxDistance, roads, mask);
    }
    return ans;
  }

private:
  static constexpr int kInf = 0x3f3f3f3f;

  static int numberOfSets(int n, int maxDistance,
                          const std::vector<std::vector<int>> &roads,
                          int mask) {
    std::vector dist(n, std::vector<int>(n, kInf));
    for (const auto &edge : roads) {
      const auto u = edge[0], v = edge[1];
      const auto w = edge[2];
      if (mask >> u & 1 && mask >> v & 1) {
        dist[u][v] = std::min(dist[u][v], w);
        dist[v][u] = std::min(dist[v][u], w);
      }
    }
    for (int u = 0; u < n; ++u) {
      if (mask >> u & 1) {
        dist[u][u] = 0;
      }
    }
    for (int w = 0; w < n; ++w) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          dist[u][v] = std::min(dist[u][v], dist[u][w] + dist[w][v]);
        }
      }
    }

    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (mask >> u & 1 && mask >> v & 1 && dist[u][v] > maxDistance) {
          return false;
        }
      }
    }
    return true;
  }
};
