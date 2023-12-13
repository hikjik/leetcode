#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minFlips(std::string target) {
    int ans = target[0] - '0';
    for (int i = 1; i < std::ssize(target); ++i) {
      ans += target[i] != target[i - 1];
    }
    return ans;
  }
};
