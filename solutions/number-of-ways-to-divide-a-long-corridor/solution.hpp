#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numberOfWays(std::string corridor) {
    int seats = 0;
    int lastSeat = -1;
    long long ans = 1;
    for (int i = 0; i < std::ssize(corridor); ++i) {
      if (corridor[i] == 'S') {
        if (++seats > 2 && seats & 1) {
          ans = ans * (i - lastSeat) % kMod;
        }
        lastSeat = i;
      }
    }
    return !seats || seats & 1 ? 0 : ans;
  }
};
