#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> sortByBits(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
      return std::forward_as_tuple(__builtin_popcount(a), a) <
             std::forward_as_tuple(__builtin_popcount(b), b);
    });
    return arr;
  }
};
