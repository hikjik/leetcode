#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1337. The K Weakest Rows in a Matrix
  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
  Difficulty: Easy
  Tags: Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> kWeakestRows(const std::vector<std::vector<int>> &mat,
                                       int k) {
    std::vector<std::pair<int, int>> soldiers;
    for (size_t i = 0; i < mat.size(); ++i) {
      const auto count = std::accumulate(mat[i].begin(), mat[i].end(), 0);
      soldiers.push_back({count, i});
    }

    std::partial_sort(soldiers.begin(), soldiers.begin() + k, soldiers.end());

    std::vector<int> weakest_rows_ids(k);
    for (int i = 0; i < k; ++i) {
      weakest_rows_ids[i] = soldiers[i].second;
    }
    return weakest_rows_ids;
  }
};
