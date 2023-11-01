#pragma once

#include <algorithm>
#include <vector>

/*
  1615. Maximal Network Rank
  https://leetcode.com/problems/maximal-network-rank/
  Difficulty: Medium
  Tags: Graph
  Time:
  Space:
*/

class Solution {
public:
  static int maximalNetworkRank(int n,
                                const std::vector<std::vector<int>> &roads) {
    std::vector<int> degree(n, 0);
    std::vector<std::vector<int>> connections(n, std::vector<int>(n, 0));

    for (const auto &edge : roads) {
      degree[edge[0]]++, degree[edge[1]]++;
      connections[edge[0]][edge[1]] = 1;
      connections[edge[1]][edge[0]] = 1;
    }

    int max_rank = 0;
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (u == v) {
          continue;
        }
        max_rank =
            std::max(max_rank, degree[u] + degree[v] - connections[u][v]);
      }
    }
    return max_rank;
  }
};
