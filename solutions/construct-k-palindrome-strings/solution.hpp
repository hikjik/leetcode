#pragma once

#include <array>
#include <ranges>
#include <string>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static bool canConstruct(std::string s, int k) {
    if (std::ssize(s) < k) {
      return false;
    }

    std::array<int, 26> cnt{};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    return std::ranges::count_if(cnt, [](int a) { return a & 1; }) <= k;
  }
};
