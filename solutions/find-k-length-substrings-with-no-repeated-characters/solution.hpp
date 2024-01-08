#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int numKLenSubstrNoRepeats(std::string s, int k) {
    std::vector<int> cnt(128);
    int uniq = 0;
    int ans = 0;
    for (int i = 0; i < std::ssize(s); ++i) {
      uniq += !cnt[s[i]]++;
      if (i >= k - 1) {
        ans += uniq == k;
        uniq -= !--cnt[s[i - k + 1]];
      }
    }
    return ans;
  }
};
