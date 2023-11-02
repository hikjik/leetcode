#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string categorizeBox(int length, int width, int height,
                                   int mass) {
    const auto volume = 1LL * width * height * length;
    const auto isBulky =
        length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9;
    const auto isHeavy = mass >= 100;

    if (isBulky && isHeavy) {
      return "Both";
    }
    if (isBulky) {
      return "Bulky";
    }
    if (isHeavy) {
      return "Heavy";
    }
    return "Neither";
  }
};
