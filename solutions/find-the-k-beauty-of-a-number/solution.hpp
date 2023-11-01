#pragma once

#include <string>

/*
  2269. Find the K-Beauty of a Number
  https://leetcode.com/problems/find-the-k-beauty-of-a-number/
  Difficulty: Easy
  Tags: Math, String, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int divisorSubstrings(int num, int k) {
    int cnt = 0;
    const auto s = std::to_string(num);
    for (size_t i = 0; i + k - 1 < s.size(); ++i) {
      const auto d = std::stoi(s.substr(i, k));
      if (d && num % d == 0) {
        ++cnt;
      }
    }
    return cnt;
  }
};
