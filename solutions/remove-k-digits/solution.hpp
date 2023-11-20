#pragma once

#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string removeKdigits(std::string num, int k) {
    std::string ans;
    for (auto c : num) {
      while (!ans.empty() && k && ans.back() > c) {
        ans.pop_back();
        --k;
      }
      if (c != '0' || !ans.empty()) {
        ans += c;
      }
    }
    return k >= std::ssize(ans) ? "0" : ans.substr(0, ans.size() - k);
  }
};
