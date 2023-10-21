#pragma once

#include <vector>

class Solution {
public:
  static bool isOneBitCharacter(const std::vector<int> &bits) {
    bool last_1bit = false;
    for (int i = 0; i < std::ssize(bits); ++i) {
      last_1bit = !bits[i];
      i += bits[i];
    }
    return last_1bit;
  }
};
