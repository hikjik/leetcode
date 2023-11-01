#pragma once

#include <string>
#include <vector>

/*
  942. DI String Match
  https://leetcode.com/problems/di-string-match/
  Difficulty: Easy
  Tags: Array, Two Pointers, String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> diStringMatch(std::string s) {
    std::vector<int> ans;
    int min = 0, max = s.size();
    for (auto c : s) {
      ans.push_back(c == 'D' ? max-- : min++);
    }
    ans.push_back(max);
    return ans;
  }
};
