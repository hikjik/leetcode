#pragma once

#include <string>

/*
  1370. Increasing Decreasing String
  https://leetcode.com/problems/increasing-decreasing-string/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static std::string sortString(std::string s) {
    std::vector<int> counter(26);
    for (auto c : s) {
      ++counter[c - 'a'];
    }

    std::string ans;
    while (ans.size() < s.size()) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (counter[c - 'a']-- > 0) {
          ans.push_back(c);
        }
      }
      for (char c = 'z'; c >= 'a'; --c) {
        if (counter[c - 'a']-- > 0) {
          ans.push_back(c);
        }
      }
    }
    return ans;
  }
};
