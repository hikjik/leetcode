#pragma once

#include <algorithm>
#include <vector>

/*
  1494. Parallel Courses II
  https://leetcode.com/problems/parallel-courses-ii/
  Difficulty: Hard
  Tags: Dynamic Programming, Bit Manipulation, Graph, Bitmask
  Time:
  Space:
*/

class Solution {
public:
  static int
  minNumberOfSemesters(int n, const std::vector<std::vector<int>> &relations,
                       int k) {
    std::vector<int> requirements(n);
    for (const auto &relation : relations) {
      const int u = relation[0] - 1, v = relation[1] - 1;
      requirements[v] |= 1 << u;
    }

    std::vector<int> dp(1 << n, n);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
      int next_courses = 0;
      for (int v = 0; v < n; ++v) {
        if ((mask & requirements[v]) == requirements[v]) {
          next_courses |= 1 << v;
        }
      }
      next_courses &= ~mask;
      for (int subset = next_courses; subset;
           subset = (subset - 1) & next_courses) {
        if (__builtin_popcount(subset) <= k) {
          dp[mask | subset] = std::min(dp[mask | subset], dp[mask] + 1);
        }
      }
    }

    return dp.back();
  }
};
