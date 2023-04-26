#pragma once

class Solution {
public:
  static int addDigits(int num) { return (num - 1) % 9 + 1; };
};
