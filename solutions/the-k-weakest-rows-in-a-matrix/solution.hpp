#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<int> kWeakestRows(const std::vector<std::vector<int>> &mat,
                                       int k) {
    int n = mat.size();
    std::priority_queue<std::pair<int, int>> queue;
    for (int i = 0; i < n; ++i) {
      auto it = std::find(mat[i].begin(), mat[i].end(), 0);
      const int weakness = std::distance(it, mat[i].end());
      queue.emplace(weakness, -i);
    }

    std::vector<int> weakest_rows(k);
    for (int i = 0; i < k; ++i) {
      weakest_rows[i] = -queue.top().second;
      queue.pop();
    }
    return weakest_rows;
  }
};
