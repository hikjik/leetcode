#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static inline const std::string kAlphabet = "abcdefghijklmnopqrstuvwxyz";

public:
  static std::string reorganizeString(std::string s) {
    std::vector<int> cnt(128, 0);
    for (auto c : s) {
      ++cnt[c];
    }

    char max_char = 'a';
    for (auto c : kAlphabet) {
      if (cnt[c] > cnt[max_char]) {
        max_char = c;
      }
    }

    if (cnt[max_char] * 1UL > (s.size() + 1) / 2) {
      return "";
    }

    size_t i = 0;
    std::string ans = s;
    for (auto c : max_char + kAlphabet) {
      while (cnt[c]) {
        --cnt[c];
        if (i >= ans.size()) {
          i = 1;
        }
        ans[i] = c;
        i += 2;
      }
    }
    return ans;
  }
};
