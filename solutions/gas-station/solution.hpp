#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int canCompleteCircuit(const std::vector<int> &gas,
                                const std::vector<int> &cost) {
    int total_diff = 0, cur_diff = 0;
    size_t start_position = 0;
    for (size_t i = 0; i < gas.size(); ++i) {
      cur_diff += gas[i] - cost[i];
      total_diff += gas[i] - cost[i];
      if (cur_diff < 0) {
        start_position = i + 1;
        cur_diff = 0;
      }
    }
    return total_diff >= 0 ? start_position : -1;
  }
};
