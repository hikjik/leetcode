#pragma once

#include <algorithm>
#include <vector>

/*
  435. Non-overlapping Intervals
  https://leetcode.com/problems/non-overlapping-intervals/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int eraseOverlapIntervals(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    int cnt = 0, end = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (std::min(end, intervals[i][1]) > intervals[i][0]) {
        cnt++;
        end = std::min(end, intervals[i][1]);
      } else {
        end = std::max(end, intervals[i][1]);
      }
    }
    return cnt;
  }
};
