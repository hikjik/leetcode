#pragma once

#include <algorithm>
#include <limits>
#include <vector>

/*
  1014. Best Sightseeing Pair
  https://leetcode.com/problems/best-sightseeing-pair/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int maxScoreSightseeingPair(const std::vector<int> &values) {
    int n = values.size();
    int max_score = std::numeric_limits<int>::min();
    int max_score_before = 0;
    for (int i = 0; i < n - 1; ++i) {
      max_score_before = std::max(max_score_before, values[i] + i);
      max_score = std::max(max_score, max_score_before + values[i + 1] - i - 1);
    }
    return max_score;
  }
};
