#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int findMinimumOperations(std::string s1, std::string s2,
                                   std::string s3) {
    if (s1[0] != s2[0] || s2[0] != s3[0]) {
      return -1;
    }
    const int minLen = std::min({s1.size(), s2.size(), s3.size()});

    int ans = s1.size() + s2.size() + s3.size();
    for (int i = 0; i < minLen && s1[i] == s2[i] && s2[i] == s3[i]; ++i) {
      ans -= 3;
    }
    return ans;
  }
};
