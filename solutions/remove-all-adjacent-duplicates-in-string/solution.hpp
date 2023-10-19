#pragma once

#include <string>

class Solution {
public:
  static std::string removeDuplicates(std::string s) {
    std::string ans;
    for (auto c : s) {
      if (!ans.empty() && ans.back() == c) {
        ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }
    return ans;
  }
};
