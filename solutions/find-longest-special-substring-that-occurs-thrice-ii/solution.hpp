#pragma once

#include <string>
#include <vector>

// A is the alphabet size
// Time: O(N)
// Space: O(NA)

class Solution {
public:
  static int maximumLength(std::string s) {
    const int n = s.size();
    std::vector cnt(26, std::vector<int>(n + 1));
    int ans = -1;
    for (int i = 0, j = i; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j]; ++j) {
      }
      for (int l = std::max(1, j - i - 2); l <= j - i; ++l) {
        cnt[s[i] - 'a'][l] += j - i - l + 1;
        if (cnt[s[i] - 'a'][l] > 2) {
          ans = std::max(ans, l);
        }
      }
    }
    return ans;
  }
};
