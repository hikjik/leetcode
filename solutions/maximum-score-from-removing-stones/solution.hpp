#pragma once

#include <algorithm>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static int maximumScore(int a, int b, int c) {
    return std::min((a + b + c) / 2, a + b + c - std::max({a, b, c}));
  }
};
