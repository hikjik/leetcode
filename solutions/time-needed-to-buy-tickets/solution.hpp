#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int timeRequiredToBuy(const std::vector<int> &tickets, int k) {
    int time = 0;
    for (int i = 0; i < std::ssize(tickets); ++i) {
      time += std::min(tickets[i], tickets[k] - (i > k));
    }
    return time;
  }
};
