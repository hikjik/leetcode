#pragma once

#include <array>
#include <string>
#include <vector>

// N = source.size()
// M = original.size()
// A = 26
// Time: O(A^3+M+N)
// Space: O(A^2)

class Solution {
public:
  static constexpr int kInf = 0x3f3f3f3f;
  static constexpr int kSize = 26;

  static long long minimumCost(std::string source, std::string target,
                               const std::vector<char> &original,
                               const std::vector<char> &changed,
                               const std::vector<int> &cost) {
    std::array<std::array<int, kSize>, kSize> dist;
    for (int u = 0; u < kSize; ++u) {
      for (int v = 0; v < kSize; ++v) {
        dist[u][v] = kInf;
      }
      dist[u][u] = 0;
    }

    for (int k = 0; k < std::ssize(original); ++k) {
      const int u = original[k] - 'a', v = changed[k] - 'a';
      dist[u][v] = std::min(dist[u][v], cost[k]);
    }

    for (int w = 0; w < kSize; ++w) {
      for (int u = 0; u < kSize; ++u) {
        for (int v = 0; v < kSize; ++v) {
          dist[u][v] = std::min(dist[u][v], dist[u][w] + dist[w][v]);
        }
      }
    }

    long long ans = 0;
    for (int k = 0; k < std::ssize(source); ++k) {
      const int u = source[k] - 'a', v = target[k] - 'a';
      if (dist[u][v] == kInf) {
        return -1;
      }
      ans += dist[u][v];
    }
    return ans;
  }
};
