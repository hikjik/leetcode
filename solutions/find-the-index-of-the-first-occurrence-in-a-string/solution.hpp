#pragma once

#include <string>
#include <vector>

/*
  28. Find the Index of the First Occurrence in a String
  https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
  Difficulty: Easy
  Tags: Two Pointers, String, String Matching
  Time: O(N+M)
  Space: O(M)
  Notes: [Knuth Morris Pratt Algorithm](https://w.wiki/7$3A)
*/

class Solution {
public:
  static int strStr(std::string haystack, std::string needle) {
    int n = haystack.size(), m = needle.size();
    if (n < m) {
      return -1;
    }

    const auto lps = LPS(needle);

    int i = 0, j = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        i++, j++;
        if (j == m) {
          return i - m;
        }
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return -1;
  }

private:
  static std::vector<int> LPS(const std::string &str) {
    std::vector<int> lps(str.size(), 0);
    for (size_t i = 1; i < str.size(); ++i) {
      int j = lps[i - 1];
      while (j && str[j] != str[i]) {
        j = lps[j - 1];
      }
      if (str[i] == str[j]) {
        ++j;
      }
      lps[i] = j;
    }
    return lps;
  }
};
