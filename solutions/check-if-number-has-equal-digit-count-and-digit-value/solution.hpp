#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool digitCount(std::string num) {
    std::vector<int> counter(10);
    for (auto c : num) {
      ++counter[c - '0'];
    }

    for (size_t i = 0; i < num.size(); ++i) {
      if (num[i] - '0' != counter[i]) {
        return false;
      }
    }
    return true;
  }
};
