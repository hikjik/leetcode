#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int wateringPlants(const std::vector<int> &plants, int capacity) {
    int ans = 0;
    for (int water = capacity, i = 0; i < std::ssize(plants); ++i) {
      if (water < plants[i]) {
        ans += 2 * i;
        water = capacity;
      }
      water -= plants[i];
    }
    return ans + plants.size();
  }
};
