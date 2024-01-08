#pragma once

#include <array>
#include <string>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static bool canPermutePalindrome(std::string s) {
    std::array<int, 26> cnt{};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }
    return std::ranges::count_if(cnt, [](int a) { return a & 1; }) < 2;
  }
};
