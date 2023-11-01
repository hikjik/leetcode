#pragma once

#include <string>
#include <vector>

/*
  516. Longest Palindromic Subsequence
  https://leetcode.com/problems/longest-palindromic-subsequence/
  Difficulty: Medium
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestPalindromeSubseq(std::string s) {
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), -1));
    return lps(0, s.size() - 1, s, &dp);
  }

private:
  static int lps(size_t left, size_t right, const std::string &s,
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
      length = 2 + lps(left + 1, right - 1, s, dp);
    } else {
      length =
          std::max(lps(left + 1, right, s, dp), lps(left, right - 1, s, dp));
    }
    return length;
  }
};
