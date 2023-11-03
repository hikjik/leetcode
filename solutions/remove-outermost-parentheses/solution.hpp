#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string removeOuterParentheses(std::string s) {
    std::string ans;
    int cnt = 0;
    for (auto c : s) {
      if (c == '(' && cnt++ || c == ')' && --cnt) {
        ans.push_back(c);
      }
    }
    return ans;
  }
};
