#pragma once

#include <string>

class Solution {
public:
  static std::string countAndSay(int n) {
    std::string s = "1";
    while (--n) {
      std::string t;
      for (size_t i = 0; i < s.size(); ++i) {
        int count = 1;
        for (; i + 1 < s.size() && s[i] == s[i + 1]; ++i) {
          ++count;
        }
        t += std::to_string(count) + s[i];
      }
      s.swap(t);
    }
    return s;
  }
};
