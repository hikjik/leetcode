#pragma once

class Solution {
public:
  static int sumBase(int n, int k) {
    int sum = 0;
    for (int i = n; i; i /= k) {
      sum += i % k;
    }
    return sum;
  }
};
