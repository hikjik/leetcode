#pragma once

#include <string>
#include <vector>

/*
  1312. Minimum Insertion Steps to Make a String Palindrome
  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
  Difficulty: Hard
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int minInsertions(std::string s) {
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), -1));
    return s.size() - longestPalindromeSubseq(0, s.size() - 1, s, &dp);
  }

private:
  static int longestPalindromeSubseq(size_t left, size_t right,
                                     const std::string &s,
                                     std::vector<std::vector<int>> *dp) {
    if (left > right) {
      return 0;
    }
    if (left == right) {
      return 1;
    }

    auto &length = (*dp)[left][right];
    if (length != -1) {
      return length;
    }
    if (s[left] == s[right]) {
      length = 2 + longestPalindromeSubseq(left + 1, right - 1, s, dp);
    } else {
      length = std::max(longestPalindromeSubseq(left + 1, right, s, dp),
                        longestPalindromeSubseq(left, right - 1, s, dp));
    }
    return length;
  }
};
