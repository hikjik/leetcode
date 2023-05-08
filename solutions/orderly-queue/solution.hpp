#pragma once

#include <algorithm>
#include <string>

class Solution {
private:
  static bool less(const std::string &s, size_t l, size_t r) {
    for (size_t i = 0; i < s.size(); ++i) {
      const auto s1 = s[(l + i) % s.size()];
      const auto s2 = s[(r + i) % s.size()];
      if (s1 != s2) {
        return s1 < s2;
      }
    }
    return true;
  }

  static size_t min_position(const std::string &s) {
    size_t i = 0;
    for (size_t j = 1; j < s.size(); ++j) {
      if (less(s, j, i)) {
        i = j;
      }
    }
    return i;
  }

public:
  static std::string orderlyQueue(std::string s, int k) {
    if (k == 1) {
      std::rotate(s.begin(), s.begin() + min_position(s), s.end());
    } else {
      std::sort(s.begin(), s.end());
    }
    return s;
  }
};
