#pragma once

#include <bitset>
#include <string>

// Time: O(N)
// Space: (A) where A is the alphabet size (26)

class Solution {
public:
  static int countPalindromicSubsequence(std::string s) {
    int ans = 0;
    for (auto c = 'a'; c <= 'z'; ++c) {
      const auto first = s.find_first_of(c), last = s.find_last_of(c);
      if (first != last) {
        std::bitset<26> bitset;
        for (auto i = first + 1; i < last; ++i) {
          bitset.set(s[i] - 'a');
        }
        ans += bitset.count();
      }
    }
    return ans;
  }
};
