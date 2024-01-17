#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int badSensor(const std::vector<int> &sensor1,
                       const std::vector<int> &sensor2) {
    const int n = sensor1.size();

    int i = 0;
    while (i < n && sensor1[i] == sensor2[i]) {
      ++i;
    }
    while (i + 1 < n && sensor1[i + 1] == sensor2[i] &&
           sensor1[i] == sensor2[i + 1]) {
      ++i;
    }
    if (i + 1 >= n) {
      return -1;
    }
    return sensor1[i + 1] == sensor2[i] ? 2 : 1;
  }
};
