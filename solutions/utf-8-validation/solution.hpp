#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool validUtf8(const std::vector<int> &data) {
    int remain = 0;
    for (auto b : data) {
      if (remain) {
        if ((b >> 6) != 0b10) {
          return false;
        }
        --remain;
      } else {
        if ((b >> 3) == 0b11110) {
          remain = 3;
        } else if ((b >> 4) == 0b1110) {
          remain = 2;
        } else if ((b >> 5) == 0b110) {
          remain = 1;
        } else if (b >> 7) {
          return false;
        }
      }
    }
    return !remain;
  }
};
