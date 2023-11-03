#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool backspaceCompare(std::string s, std::string t) {
    while (!s.empty() || !t.empty()) {
      trimRight(s);
      trimRight(t);
      if (!s.empty() && !t.empty() && s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
      } else {
        break;
      }
    }
    return s.empty() && t.empty();
  }

private:
  static void trimRight(std::string &s) {
    int cnt = 0;
    while (!s.empty()) {
      if (s.back() == '#') {
        cnt++;
        s.pop_back();
      } else if (cnt) {
        s.pop_back();
        cnt--;
      } else {
        break;
      }
    }
  }
};
