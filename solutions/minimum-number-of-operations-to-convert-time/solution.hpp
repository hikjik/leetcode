#pragma once

#include <string>

/*
  2224. Minimum Number of Operations to Convert Time
  https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
  Difficulty: Easy
  Tags: String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int convertTime(std::string current, std::string correct) {
    int diff = std::abs(toMinutes(current) - toMinutes(correct));
    int ops = 0;
    for (auto d : {60, 15, 5, 1}) {
      ops += diff / d;
      diff %= d;
    }
    return ops;
  }

private:
  static int toMinutes(std::string time) {
    return std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3));
  }
};
