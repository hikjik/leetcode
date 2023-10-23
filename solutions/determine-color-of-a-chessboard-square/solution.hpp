#pragma once

#include <string>

class Solution {
public:
  static bool squareIsWhite(std::string coordinates) {
    return (coordinates[0] & 1) ^ (coordinates[1] & 1);
  }
};
