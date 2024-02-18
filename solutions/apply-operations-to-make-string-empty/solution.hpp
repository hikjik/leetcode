#pragma once

#include <array>
#include <ranges>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string lastNonEmptyString(std::string s) {
    std::array<int, 26> cnt{};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }
    const int max = std::ranges::max(cnt);
    std::string ans;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (cnt[s[i] - 'a'] == max) {
        cnt[s[i] - 'a'] = 0;
        ans += s[i];
      }
    }
    std::ranges::reverse(ans);
    return ans;
  }
};
