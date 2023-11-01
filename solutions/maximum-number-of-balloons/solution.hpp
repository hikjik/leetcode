#pragma once

#include <climits>
#include <string>
#include <unordered_map>

/*
  1189. Maximum Number of Balloons
  https://leetcode.com/problems/maximum-number-of-balloons/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int maxNumberOfBalloons(std::string text) {
    auto map = buildMap(text);
    int ans = INT_MAX;
    for (const auto &[c, f] : buildMap("balloon")) {
      ans = std::min(ans, map[c] / f);
    }
    return ans;
  }

  static std::unordered_map<char, int> buildMap(std::string str) {
    std::unordered_map<char, int> map;
    for (auto c : str) {
      ++map[c];
    }
    return map;
  }
};
