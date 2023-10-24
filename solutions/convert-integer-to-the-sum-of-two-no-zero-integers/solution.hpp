#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; ++i) {
      if (std::to_string(i).find('0') == std::string::npos &&
          std::to_string(n - i).find('0') == std::string::npos) {
        return {i, n - i};
      }
    }

    throw;
  }
};
