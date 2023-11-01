#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  2141. Maximum Running Time of N Computers
  https://leetcode.com/problems/maximum-running-time-of-n-computers/
  Difficulty: Hard
  Tags: Array, Binary Search, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static long long maxRunTime(int n, std::vector<int> batteries) {
    const int m = batteries.size();
    std::sort(batteries.begin(), batteries.end());

    auto power = std::accumulate(batteries.begin(), batteries.end() - n, 0LL);
    for (int i = 0; i < n - 1; ++i) {
      const auto extra =
          (i + 1LL) * (batteries[m - n + i + 1] - batteries[m - n + i]);
      if (power < extra) {
        return batteries[m - n + i] + power / (i + 1);
      }
      power -= extra;
    }
    return batteries.back() + power / n;
  }
};
