#pragma once

#include <vector>

/*
  1450. Number of Students Doing Homework at a Given Time
  https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int busyStudent(std::vector<int> startTime, std::vector<int> endTime,
                         int queryTime) {
    int cnt = 0;
    for (int i = 0; i < std::ssize(startTime); ++i) {
      if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
        ++cnt;
      }
    }
    return cnt;
  }
};
