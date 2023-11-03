#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int getWinner(const std::vector<int> &arr, int k) {
    int winner = arr[0], wins = -1;
    for (auto a : arr) {
      a > winner ? winner = a, wins = 1 : ++wins;
      if (wins == k) {
        break;
      }
    }
    return winner;
  }
};
