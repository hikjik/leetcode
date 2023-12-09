#pragma once

#include <vector>

// Time: O(NM)
// Space: O(NM)

class Solution {
public:
  static int countSquares(std::vector<std::vector<int>> matrix) {
    int ans = 0;
    for (int i = 0; i < std::ssize(matrix); ++i) {
      for (int j = 0; j < std::ssize(matrix[i]); ++j) {
        if (i && j && matrix[i][j]) {
          matrix[i][j] += std::min({
              matrix[i - 1][j - 1],
              matrix[i][j - 1],
              matrix[i - 1][j],
          });
        }
        ans += matrix[i][j];
      }
    }
    return ans;
  }
};
