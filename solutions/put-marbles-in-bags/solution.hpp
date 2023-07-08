#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static long long putMarbles(const std::vector<int> &weights, size_t k) {
    std::vector<int> sums;
    for (size_t i = 0; i + 1 < weights.size(); ++i) {
      sums.push_back(weights[i] + weights[i + 1]);
    }
    std::sort(sums.begin(), sums.end());

    long long answer = 0;
    for (size_t i = 0; i < k - 1; ++i) {
      answer += sums[sums.size() - i - 1] - sums[i];
    }
    return answer;
  }
};
