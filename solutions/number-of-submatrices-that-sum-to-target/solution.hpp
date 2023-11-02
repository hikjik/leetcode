#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int numSubmatrixSumTarget(std::vector<std::vector<int>> mat,
                                   int target) {
    const int rows = mat.size(), cols = mat.back().size();

    for (auto &row : mat) {
      std::partial_sum(row.begin(), row.end(), row.begin());
    }

    int cnt = 0;
    for (int col1 = 0; col1 < cols; ++col1) {
      for (int col2 = col1; col2 < cols; ++col2) {

        int sum = 0;
        std::unordered_map<int, int> map{{0, 1}};
        for (int row = 0; row < rows; ++row) {
          if (col1) {
            mat[row][col2] -= mat[row][col1 - 1];
          }

          sum += mat[row][col2];
          if (auto it = map.find(sum - target); it != map.end()) {
            cnt += it->second;
          }
          ++map[sum];
        }
      }
    }
    return cnt;
  }
};
