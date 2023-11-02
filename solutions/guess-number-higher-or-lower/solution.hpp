#pragma once

#include "api.hpp"

#include <cassert>

// Time:
// Space:

class Solution {
public:
  static int guessNumber(int n) {
    int left = 1;
    int right = n;
    while (left <= right) {
      const int middle = left + (right - left) / 2;

      switch (guess(middle)) {
      case 0:
        return middle;
      case 1:
        left = middle + 1;
        break;

      case -1:
        right = middle - 1;
        break;

      default:
        assert(false && "Unreachable");
        break;
      }
    }

    return -1;
  }
};
