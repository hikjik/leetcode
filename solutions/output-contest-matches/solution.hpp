#pragma once

#include <string>
#include <vector>

// Time: O(NlogN)
// Space: O(NlogN)

class Solution {
public:
  static std::string findContestMatch(int n) {
    std::vector<std::string> matches;
    for (int i = 1; i <= n; ++i) {
      matches.push_back(std::to_string(i));
    }
    for (int m = n; m > 1; m = m / 2) {
      for (int i = 0; i < m / 2; ++i) {
        matches[i] = "(" + matches[i] + "," + matches[m - i - 1] + ")";
      }
    }
    return matches[0];
  }
};
