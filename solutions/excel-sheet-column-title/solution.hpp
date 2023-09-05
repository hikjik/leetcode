#pragma once

#include <algorithm>
#include <string>

class Solution {
private:
  const int kAlphabetSize = 26;

public:
  std::string convertToTitle(int columnNumber) {
    std::string title;
    while (columnNumber--) {
      title += 'A' + columnNumber % kAlphabetSize;
      columnNumber /= kAlphabetSize;
    }
    std::reverse(title.begin(), title.end());
    return title;
  }
};
