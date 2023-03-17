#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string minWindow(std::string s, std::string t) {
    std::vector<int> counter(128, 0);
    for (auto c : t) {
      counter[c]++;
    }
    auto cnt = t.size();

    auto min_length = s.size() + 1;
    auto min_pos = std::string::npos;
    for (size_t l = 0, r = 0; r < s.size(); ++r) {
      if (--counter[s[r]] >= 0) {
        cnt--;
      }
      while (!cnt) {
        if (r - l + 1 < min_length) {
          min_length = r - l + 1;
          min_pos = l;
        }
        if (++counter[s[l++]] > 0) {
          cnt++;
        }
      }
    }
    return min_pos == std::string::npos ? "" : s.substr(min_pos, min_length);
  }
};