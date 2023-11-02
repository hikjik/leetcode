#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxSatisfaction(std::vector<int> satisfaction) {
    std::sort(satisfaction.rbegin(), satisfaction.rend());
    int max = 0, sum = 0;
    for (auto s : satisfaction) {
      if (sum + s < 0) {
        break;
      }
      sum += s;
      max += sum;
    }
    return max;
  }
};
