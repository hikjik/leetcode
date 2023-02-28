#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int>
  findSmallestSetOfVertices(int n, const std::vector<std::vector<int>> &edges) {
    std::vector<int> in_degree(n, 0);
    for (const auto &edge : edges) {
      in_degree[edge[1]]++;
    }

    std::vector<int> smallest_set;
    for (int i = 0; i < n; ++i) {
      if (in_degree[i] == 0) {
        smallest_set.push_back(i);
      }
    }
    return smallest_set;
  }
};
