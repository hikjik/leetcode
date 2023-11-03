#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool canThreePartsEqualSum(const std::vector<int> &arr) {
    std::vector<int> sum(arr.size());
    std::partial_sum(arr.begin(), arr.end(), sum.begin());
    if (sum.back() % 3 != 0) {
      return false;
    }

    auto it1 = std::find(sum.begin(), sum.end(), sum.back() / 3);
    auto it2 = std::find(std::next(it1), sum.end(), 2 * sum.back() / 3);
    return it2 != sum.end() && it2 != std::prev(sum.end());
  }
};
