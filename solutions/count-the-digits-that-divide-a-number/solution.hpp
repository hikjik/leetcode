#pragma once

// Time:
// Space:

class Solution {
public:
  static int countDigits(int num) {
    int cnt = 0;
    for (int i = num; i; i /= 10) {
      if (int digit = i % 10; num % digit == 0) {
        ++cnt;
      }
    }
    return cnt;
  }
};
