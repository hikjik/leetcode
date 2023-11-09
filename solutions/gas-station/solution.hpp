#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int canCompleteCircuit(const std::vector<int> &gas,
                                const std::vector<int> &cost) {
    if (std::reduce(gas.begin(), gas.end()) <
        std::reduce(cost.begin(), cost.end())) {
      return -1;
    }

    int station = 0, tank = 0;
    for (int i = 0; i < std::ssize(gas); ++i) {
      tank += gas[i] - cost[i];
      if (tank < 0) {
        station = i + 1;
        tank = 0;
      }
    }
    return station;
  }
};
