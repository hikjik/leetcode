#pragma once

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static double nthPersonGetsNthSeat(int n) { return n == 1 ? 1 : 0.5; }
};
