#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  424. Longest Repeating Character Replacement
  https://leetcode.com/problems/longest-repeating-character-replacement/
  Difficulty: Medium
  Tags: Hash Table, String, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int characterReplacement(std::string s, int k) {
    int n = s.size();
    std::vector<int> counter(128, 0);

    int max_length = 0, max_freq = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      max_freq = std::max(max_freq, ++counter[s[j]]);
      while (max_freq + k < j - i + 1) {
        --counter[s[i++]];
      }
      max_length = std::max(max_length, j - i + 1);
    }
    return max_length;
  }
};
