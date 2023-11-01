#pragma once

#include <map>
#include <vector>

/*
  436. Find Right Interval
  https://leetcode.com/problems/find-right-interval/
  Difficulty: Medium
  Tags: Array, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  findRightInterval(const std::vector<std::vector<int>> &intervals) {
    std::map<int, int> map;
    for (size_t i = 0; i < intervals.size(); ++i) {
      map[intervals[i][0]] = i;
    }

    std::vector<int> indexes;
    for (const auto &interval : intervals) {
      auto lb = map.lower_bound(interval[1]);
      const auto index = lb != map.end() ? lb->second : -1;
      indexes.push_back(index);
    }
    return indexes;
  }
};
