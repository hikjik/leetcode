#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minChanges(std::string s) {
    int cnt = 0;
    for (int i = 0; i < std::ssize(s); i += 2) {
      cnt += s[i] != s[i + 1];
    }
    return cnt;
  }
};
