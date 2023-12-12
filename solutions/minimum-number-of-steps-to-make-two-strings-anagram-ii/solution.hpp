#pragma once

#include <array>
#include <numeric>
#include <string>

// Time: O(N+M)
// Space: O(A)

class Solution {
public:
  static int minSteps(std::string s, std::string t) {
    std::array<int, 26> cnt{};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }
    for (auto c : t) {
      --cnt[c - 'a'];
    }
    return std::accumulate(cnt.begin(), cnt.end(), 0,
                           [](int a, int b) { return a + std::abs(b); });
  }
};
