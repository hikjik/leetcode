#pragma once

#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    std::unordered_map<char, int> cnt;
    int uniq = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(s); ++r) {
      uniq += !cnt[s[r]]++;
      while (uniq > k) {
        uniq -= !--cnt[s[l++]];
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
