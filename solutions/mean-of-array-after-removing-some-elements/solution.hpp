#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  static double trimMean(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    const auto trim = arr.size() / 20;
    const auto count = arr.size() - 2 * trim;
    const auto sum = std::accumulate(arr.begin() + trim, arr.end() - trim, 0);
    return sum * 1.0 / count;
  }
};
