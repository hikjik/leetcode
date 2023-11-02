#pragma once

#include <queue>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string predictPartyVictory(std::string senate) {
    const int n = senate.size();

    std::queue<int> radiantQueue, direQueue;
    for (int i = 0; i < n; ++i) {
      senate[i] == 'R' ? radiantQueue.push(i) : direQueue.push(i);
    }

    while (!radiantQueue.empty() && !direQueue.empty()) {
      const auto r = radiantQueue.front(), d = direQueue.front();
      radiantQueue.pop(), direQueue.pop();
      r < d ? radiantQueue.push(r + n) : direQueue.push(d + n);
    }

    return direQueue.empty() ? "Radiant" : "Dire";
  }
};
