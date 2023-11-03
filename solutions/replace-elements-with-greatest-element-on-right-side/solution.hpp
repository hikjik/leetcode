#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> replaceElements(const std::vector<int> &arr) {
    std::vector<int> ans(arr.size());
    for (int i = arr.size() - 1, max = -1; i >= 0; --i) {
      ans[i] = max;
      max = std::max(max, arr[i]);
    }
    return ans;
  }
};
