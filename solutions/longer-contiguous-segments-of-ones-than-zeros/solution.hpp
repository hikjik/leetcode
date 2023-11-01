#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  1869. Longer Contiguous Segments of Ones than Zeros
  https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool checkZeroOnes(std::string s) {
    std::vector<size_t> longest(2);
    for (size_t i = 0, j = 1; i < s.size(); ++j) {
      if (j == s.size() || s[i] != s[j]) {
        longest[s[i] - '0'] = std::max(longest[s[i] - '0'], j - i);
        i = j;
      }
    }
    return longest[1] > longest[0];
  }
};
