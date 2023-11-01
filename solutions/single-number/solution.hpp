#pragma once

#include <vector>

/*
  136. Single Number
  https://leetcode.com/problems/single-number/
  Difficulty: Easy
  Tags: Array, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int singleNumber(const std::vector<int> &numbers) {
    int answer = 0;
    for (auto number : numbers) {
      answer ^= number;
    }
    return answer;
  }
};
