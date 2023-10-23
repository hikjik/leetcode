#pragma once

#include <utility>

class Solution {
public:
  static int countOperations(int num1, int num2) {
    int ops = 0;
    while (num1 && num2) {
      if (num1 < num2) {
        std::swap(num1, num2);
      }
      ops += num1 / num2;
      num1 %= num2;
    }
    return ops;
  }
};
