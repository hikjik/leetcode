#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
private:
  static const int kAlphabetSize = 26;

public:
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
