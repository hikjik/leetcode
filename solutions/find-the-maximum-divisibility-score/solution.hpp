#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxDivScore(const std::vector<int> &nums,
                         const std::vector<int> &divisors) {
    int max_score = -1, divisor = -1;
    for (auto d : divisors) {
      const auto score = std::count_if(nums.begin(), nums.end(),
                                       [d](int n) { return n % d == 0; });
      if (score > max_score) {
        max_score = score;
        divisor = d;
      } else if (score == max_score) {
        divisor = std::min(divisor, d);
      }
    }
    return divisor;
  }
};
