#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool canChange(std::string s, std::string t) {
    const int n = s.size();
    for (int i = 0, j = 0; i < n || j < n; ++i, ++j) {
      while (i < n && s[i] == '_') {
        ++i;
      }
      while (j < n && t[j] == '_') {
        ++j;
      }
      if (i == n || j == n) {
        return i == n && j == n;
      }
      if (s[i] != t[j]) {
        return false;
      }
      if (s[i] == 'L' && i < j) {
        return false;
      }
      if (t[j] == 'R' && j < i) {
        return false;
      }
    }
    return true;
  }
};
