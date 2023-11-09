#pragma once

#include <algorithm>
#include <string>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static constexpr int kAlphabetSize = 26;

  static std::string convertToTitle(int columnNumber) {
    std::string title;
    while (columnNumber--) {
      title += 'A' + columnNumber % kAlphabetSize;
      columnNumber /= kAlphabetSize;
    }
    std::reverse(title.begin(), title.end());
    return title;
  }
};
