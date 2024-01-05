#pragma once

#include <string>
#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static bool validWordSquare(const std::vector<std::string> &words) {
    for (size_t i = 0; i < words.size(); ++i) {
      for (size_t j = 0; j < words[i].size(); ++j) {
        if (j >= words.size() || i >= words[j].size() ||
            words[i][j] != words[j][i]) {
          return false;
        }
      }
    }
    return true;
  }
};
