#pragma once

// Time:
// Space:

class Solution {
public:
  static int findJudge(int n, const std::vector<std::vector<int>> &trust) {
    std::vector<int> out_degree(n, 0);
    std::vector<int> in_degree(n, 0);
    for (const auto &edge : trust) {
      in_degree[edge[1] - 1]++;
      out_degree[edge[0] - 1]++;
    }
    for (int i = 0; i < n; ++i) {
      if (in_degree[i] == n - 1 && out_degree[i] == 0) {
        return i + 1;
      }
    }
    return -1;
  }
};
