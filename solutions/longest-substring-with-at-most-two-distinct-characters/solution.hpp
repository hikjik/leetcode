#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::vector<int> cnt(128);
    int uniq = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(s); ++r) {
      uniq += !cnt[s[r]]++;
      while (uniq > 2) {
        uniq -= !--cnt[s[l++]];
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
