#pragma once

#include <numeric>
#include <string>

/*
  389. Find the Difference
  https://leetcode.com/problems/find-the-difference/
  Difficulty: Easy
  Tags: Hash Table, String, Bit Manipulation, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static char findTheDifference(std::string s, std::string t) {
    return std::accumulate(t.begin(), t.end(), 0) -
           std::accumulate(s.begin(), s.end(), 0);
  }
};
