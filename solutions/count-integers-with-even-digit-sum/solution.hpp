#pragma once

class Solution {
public:
  static int countEven(int num) { return (num - digitSum(num) % 2) / 2; }

private:
  static int digitSum(int num) {
    int sum = 0;
    for (int i = num; i; i /= 10) {
      sum += i % 10;
    }
    return sum;
  }
};
