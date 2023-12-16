#pragma once

#include <climits>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static double
  averageWaitingTime(const std::vector<std::vector<int>> &customers) {
    long long waitingTime = 0;
    for (long long idleTime = 0; const auto &customer : customers) {
      const long long arrival = customer[0], time = customer[1];
      idleTime = std::max(idleTime, arrival) + time;
      waitingTime += idleTime - arrival;
    }
    return waitingTime * 1.0 / customers.size();
  }
};
