#pragma once

class Solution {
public:
  static bool isSameAfterReversals(int num) { return !num || num % 10 != 0; }
};
