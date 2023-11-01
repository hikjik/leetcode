#pragma once

#include <vector>

/*
  2073. Time Needed to Buy Tickets
  https://leetcode.com/problems/time-needed-to-buy-tickets/
  Difficulty: Easy
  Tags: Array, Queue, Simulation
  Time:
  Space:
*/

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
