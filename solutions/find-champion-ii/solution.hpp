#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int findChampion(int n, const std::vector<std::vector<int>> &edges) {
    std::vector<int> degree(n);
    for (const auto &edge : edges) {
      ++degree[edge[1]];
    }
    if (std::ranges::count(degree, 0) > 1) {
      return -1;
    }
    return std::ranges::find(degree, 0) - degree.begin();
  }
};
