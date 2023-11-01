#pragma once

#include <algorithm>
#include <vector>

/*
  744. Find Smallest Letter Greater Than Target
  https://leetcode.com/problems/find-smallest-letter-greater-than-target/
  Difficulty: Easy
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static char nextGreatestLetter(const std::vector<char> &letters,
                                 char target) {
    if (target >= letters.back()) {
      return letters.front();
    }
    return *std::upper_bound(letters.begin(), letters.end(), target);
  }
};
