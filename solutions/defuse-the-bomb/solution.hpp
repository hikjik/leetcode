#pragma once

#include <cmath>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> decrypt(const std::vector<int> &code, int k) {
    const int n = code.size();
    int sum = std::accumulate(code.begin(), code.begin() + std::abs(k), 0);
    std::vector<int> ans(code.size());
    for (int i = 0; i < n; ++i) {
      const int idx = k > 0 ? i - 1 : i - k;
      ans[(idx + n) % n] = sum;
      sum += code[(std::abs(k) + i) % n] - code[i];
    }
    return ans;
  }
};
