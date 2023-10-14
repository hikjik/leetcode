#pragma once

class Solution {
public:
  static int differenceOfSums(int n, int m) {
    return (n * (n + 1)) / 2 - (m + n / m * m) * (n / m);
  }
};
