#pragma once

#include <vector>

/*
  1700. Number of Students Unable to Eat Lunch
  https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
  Difficulty: Easy
  Tags: Array, Stack, Queue, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int countStudents(const std::vector<int> &students,
                           const std::vector<int> &sandwiches) {
    std::vector<int> cnt(2);
    for (auto s : students) {
      ++cnt[s];
    }

    for (auto s : sandwiches) {
      if (!cnt[s]) {
        break;
      }
      --cnt[s];
    }

    return cnt[0] + cnt[1];
  }
};
