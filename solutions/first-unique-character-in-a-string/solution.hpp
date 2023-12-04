#pragma once

#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int firstUniqChar(std::string s) {
    std::unordered_map<char, int> counter;
    for (auto c : s) {
      ++counter[c];
    }
    for (int i = 0; i < ssize(s); ++i) {
      if (counter[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
