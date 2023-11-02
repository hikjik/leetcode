#pragma once

// Time:
// Space:

class Solution {
public:
  static int distanceTraveled(int mainTank, int additionalTank) {
    return (mainTank + std::min((mainTank - 1) / 4, additionalTank)) * 10;
  }
};
