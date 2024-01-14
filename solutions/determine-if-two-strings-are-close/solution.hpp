#pragma once

#include <array>
#include <ranges>
#include <string>

// Time: O(N+M+AlogA)
// Space: O(A)

class Solution {
public:
  static bool closeStrings(std::string word1, std::string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }

    std::array<int, 26> cnt1{}, cnt2{};
    for (auto c : word1) {
      ++cnt1[c - 'a'];
    }
    for (auto c : word2) {
      ++cnt2[c - 'a'];
    }
    for (int i = 0; i < 26; i++) {
      if (!cnt1[i] && cnt2[i] || cnt1[i] && !cnt2[i]) {
        return false;
      }
    }

    std::ranges::sort(cnt1);
    std::ranges::sort(cnt2);
    return cnt1 == cnt2;
  }
};
