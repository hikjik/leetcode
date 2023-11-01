#pragma once

#include <string>
#include <vector>

/*
  2744. Find Maximum Number of String Pairs
  https://leetcode.com/problems/find-maximum-number-of-string-pairs/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int maximumNumberOfStringPairs(const std::vector<std::string> &words) {
    int cnt = 0;
    std::vector<bool> seen(26 * 26);
    for (const auto &w : words) {
      cnt += seen[(w[1] - 'a') * 26 + w[0] - 'a'];
      seen[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
    }
    return cnt;
  }
};
