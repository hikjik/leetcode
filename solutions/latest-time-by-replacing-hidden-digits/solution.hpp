#pragma once

#include <string>

/*
  1736. Latest Time by Replacing Hidden Digits
  https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
  Difficulty: Easy
  Tags: String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static std::string maximumTime(std::string time) {
    if (time[0] == '?') {
      time[0] = time[1] == '?' || time[1] < '4' ? '2' : '1';
    }
    if (time[1] == '?') {
      time[1] = time[0] == '2' ? '3' : '9';
    }
    time[3] = time[3] == '?' ? '5' : time[3];
    time[4] = time[4] == '?' ? '9' : time[4];
    return time;
  }
};
