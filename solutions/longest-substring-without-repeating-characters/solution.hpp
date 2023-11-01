#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

/*
  3. Longest Substring Without Repeating Characters
  https://leetcode.com/problems/longest-substring-without-repeating-characters/
  Difficulty: Medium
  Tags: Hash Table, String, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> indexes;
    int length = 0;
    for (int i = 0, j = 0; j < std::ssize(s); ++j) {
      if (indexes.contains(s[j])) {
        i = std::max(i, indexes[s[j]] + 1);
      }
      indexes[s[j]] = j;
      length = std::max(length, j - i + 1);
    }
    return length;
  }
};
