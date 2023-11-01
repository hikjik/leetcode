#pragma once

#include <algorithm>
#include <vector>

/*
  2136. Earliest Possible Day of Full Bloom
  https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
  Difficulty: Hard
  Tags: Array, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int earliestFullBloom(const std::vector<int> &plantTime,
                               const std::vector<int> &growTime) {
    std::vector<std::pair<int, int>> seeds;
    for (size_t i = 0; i < plantTime.size(); ++i) {
      seeds.emplace_back(growTime[i], plantTime[i]);
    }

    std::sort(seeds.rbegin(), seeds.rend());
    int bloom_time = 0, time = 0;
    for (const auto &[grow, plant] : seeds) {
      time += plant;
      bloom_time = std::max(bloom_time, time + grow);
    }
    return bloom_time;
  }
};
