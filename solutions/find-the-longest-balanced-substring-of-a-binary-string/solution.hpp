#pragma once

#include <string>

/*
  2609. Find the Longest Balanced Substring of a Binary String
  https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int findTheLongestBalancedSubstring(std::string s) {
    int ans = 0;
    int zeros = 0, ones = 0;
    for (auto c : s) {
      if (c == '0') {
        zeros = ones ? 1 : zeros + 1;
        ones = 0;
      } else {
        ++ones;
      }
      if (zeros >= ones) {
        ans = std::max(ans, 2 * ones);
      }
    }
    return ans;
  }
};
