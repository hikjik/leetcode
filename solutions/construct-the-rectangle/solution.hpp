#pragma once

#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> constructRectangle(int area) {
    for (int width = std::sqrt(area); width; --width) {
      if (area % width == 0) {
        return {area / width, width};
      }
    }
    throw;
  }
};
