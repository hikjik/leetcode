#pragma once

#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static std::vector<std::string> generatePossibleNextMoves(std::string s) {
    std::vector<std::string> ans;
    for (int i = 0; i + 1 < std::ssize(s); ++i) {
      if (s[i] == '+' && s[i + 1] == '+') {
        s[i] = s[i + 1] = '-';
        ans.push_back(s);
        s[i] = s[i + 1] = '+';
      }
    }
    return ans;
  }
};
