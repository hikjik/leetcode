#pragma once

#include <string>

/*
  1668. Maximum Repeating Substring
  https://leetcode.com/problems/maximum-repeating-substring/
  Difficulty: Easy
  Tags: String, String Matching
  Time:
  Space:
*/

class Solution {
public:
  static int maxRepeating(std::string sequence, std::string word) {
    int ans = 0;
    for (auto s = word; sequence.find(s) != std::string::npos; s += word) {
      ++ans;
    }
    return ans;
  }
};
