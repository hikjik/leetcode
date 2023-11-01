#pragma once

#include <algorithm>
#include <vector>

/*
  1402. Reducing Dishes
  https://leetcode.com/problems/reducing-dishes/
  Difficulty: Hard
  Tags: Array, Dynamic Programming, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int maxSatisfaction(std::vector<int> satisfaction) {
    std::sort(satisfaction.rbegin(), satisfaction.rend());
    int max = 0, sum = 0;
    for (auto s : satisfaction) {
      if (sum + s < 0) {
        break;
      }
      sum += s;
      max += sum;
    }
    return max;
  }
};
