#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool validWordAbbreviation(std::string word, std::string abbr) {
    const int n = word.size(), m = abbr.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (word[i] == abbr[j]) {
        ++i, ++j;
      } else if (std::isdigit(abbr[j])) {
        if (abbr[j] == '0') {
          return false;
        }
        int num = 0;
        do {
          num = num * 10 + (abbr[j++] - '0');
        } while (std::isdigit(abbr[j]));
        i += num;
      } else {
        return false;
      }
    }
    return i == n && j == m;
  }
};
