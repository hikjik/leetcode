#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string pushDominoes(std::string dominoes) {
    const int n = dominoes.size();
    int i = -1;
    char c = 'L';
    for (int j = 0; j <= n; ++j) {
      if (dominoes[j] == '.') {
        continue;
      }
      if (j == n && c == 'R' || dominoes[j] == c) {
        for (int k = i + 1; k < j; ++k) {
          dominoes[k] = c;
        }
      } else if (j < n && c == 'R' && dominoes[j] == 'L') {
        for (int l = i + 1, r = j - 1; l < r; ++l, --r) {
          dominoes[l] = 'R';
          dominoes[r] = 'L';
        }
      }
      i = j;
      c = dominoes[j];
    }
    return dominoes;
  }
};
