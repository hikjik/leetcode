#pragma once

#include <numeric>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int titleToNumber(std::string columnTitle) {
    return std::accumulate(columnTitle.begin(), columnTitle.end(), 0,
                           [](int a, int b) { return a * 26 + (b - 'A' + 1); });
  }
};
