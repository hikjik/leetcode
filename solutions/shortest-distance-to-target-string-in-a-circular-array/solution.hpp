#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int closetTarget(const std::vector<std::string> &words,
                          std::string target, int start) {
    const int n = words.size();
    for (int i = 0; i < n; ++i) {
      if (words[(start + i) % n] == target ||
          words[(start - i + n) % n] == target) {
        return i;
      }
    }
    return -1;
  }
};
