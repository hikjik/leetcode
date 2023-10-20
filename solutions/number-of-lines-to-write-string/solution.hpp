#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static constexpr int kMaxLineSize = 100;

  static std::vector<int> numberOfLines(const std::vector<int> &widths,
                                        std::string s) {
    int lines = 1, width = 0;
    for (auto c : s) {
      width += widths[c - 'a'];
      if (width > kMaxLineSize) {
        ++lines;
        width = widths[c - 'a'];
      }
    }
    return {lines, width};
  }
};
