#pragma once

#include <string>
#include <vector>

// Time: O(N), where N is the length of the string s
// Space: O(1), result is not included

class Solution {
public:
  static std::string convert(std::string s, int numRows) {
    if (numRows == 1 || numRows >= std::ssize(s)) {
      return s;
    }

    std::string ans;
    for (int i = 0, step = 2 * numRows - 2; i < numRows; ++i) {
      for (int j = i; j < std::ssize(s); j += step) {
        ans.push_back(s[j]);
        if (i != 0 && i != numRows - 1) {
          const auto k = j + step - 2 * i;
          if (k < std::ssize(s)) {
            ans.push_back(s[k]);
          }
        }
      }
    }
    return ans;
  }
};
