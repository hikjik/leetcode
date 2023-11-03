#pragma once

#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int chalkReplacer(const std::vector<int> &chalk, int k) {
    k %= std::accumulate(chalk.begin(), chalk.end(), 0L);

    int i = 0;
    while (k >= chalk[i]) {
      k -= chalk[i++];
    }
    return i;
  }
};
