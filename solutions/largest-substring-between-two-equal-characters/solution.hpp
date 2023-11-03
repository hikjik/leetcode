#pragma once

#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static int maxLengthBetweenEqualCharacters(std::string s) {
    std::unordered_map<char, int> seen;
    int ans = -1;
    for (int i = 0; i < std::ssize(s); ++i) {
      if (seen.contains(s[i])) {
        ans = std::max(ans, i - seen[s[i]] - 1);
      } else {
        seen[s[i]] = i;
      }
    }
    return ans;
  }
};
