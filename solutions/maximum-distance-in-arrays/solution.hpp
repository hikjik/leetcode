#pragma once

#include <climits>
#include <utility>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxDistance(const std::vector<std::vector<int>> &arrays) {
    int min = arrays.front().front(), max = arrays.front().back();
    int ans = 0;
    for (int i = 1; i < std::ssize(arrays); ++i) {
      ans = std::max({ans, arrays[i].back() - min, max - arrays[i].front()});
      min = std::min(min, arrays[i].front());
      max = std::max(max, arrays[i].back());
    }
    return ans;
  }
};
