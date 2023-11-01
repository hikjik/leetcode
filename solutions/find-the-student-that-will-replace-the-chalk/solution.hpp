#pragma once

#include <numeric>
#include <vector>

/*
  1894. Find the Student that Will Replace the Chalk
  https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
  Difficulty: Medium
  Tags: Array, Binary Search, Simulation, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int chalkReplacer(const std::vector<int> &chalk, int k) {
    k %= std::accumulate(chalk.begin(), chalk.end(), 0L);

    int i = 0;
    while (k >= chalk[i]) {
      k -= chalk[i++];
    }
    return i;
  }
};
