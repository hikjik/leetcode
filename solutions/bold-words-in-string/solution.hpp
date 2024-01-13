#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time: O(N^2+MK)
// Space: O(N+MK)

class Solution {
public:
  static std::string boldWords(const std::vector<std::string> &words,
                               const std::string &s) {
    const int n = s.size();
    std::vector<bool> bold(n);
    for (const auto &word : words) {
      for (auto pos = s.find(word); pos != std::string::npos;
           pos = s.find(word, pos + 1)) {
        std::fill_n(bold.begin() + pos, word.size(), true);
      }
    }

    std::string ans;
    for (int i = 0; i < n; ++i) {
      if (bold[i] && (i == 0 || !bold[i - 1])) {
        ans += "<b>";
      }
      ans += s[i];
      if (bold[i] && (i == n - 1 || !bold[i + 1])) {
        ans += "</b>";
      }
    }
    return ans;
  }
};
