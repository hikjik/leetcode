#pragma once

#include <vector>

class Solution {
public:
  static int sumOddLengthSubarrays(const std::vector<int> &arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      int total = (i + 1) * (arr.size() - i);
      int total_odd = (total + 1) / 2;
      sum += total_odd * arr[i];
    }
    return sum;
  }
};
