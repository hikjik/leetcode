#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string licenseKeyFormatting(std::string s, int k) {
    std::string key;
    for (int i = s.size() - 1, cnt = 0; i >= 0; --i) {
      if (s[i] != '-') {
        if (cnt && cnt % k == 0) {
          key.push_back('-');
        }
        key.push_back(std::toupper(s[i]));
        ++cnt;
      }
    }
    std::reverse(key.begin(), key.end());
    return key;
  }
};
