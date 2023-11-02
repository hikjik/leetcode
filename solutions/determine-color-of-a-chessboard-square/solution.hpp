#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool squareIsWhite(std::string coordinates) {
    return (coordinates[0] & 1) ^ (coordinates[1] & 1);
  }
};
