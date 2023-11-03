#pragma once

// Time:
// Space:

class Solution {
public:
  static int addDigits(int num) { return (num - 1) % 9 + 1; };
};
