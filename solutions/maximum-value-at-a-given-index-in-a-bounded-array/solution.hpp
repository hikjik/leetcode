#pragma once

/*
  1802. Maximum Value at a Given Index in a Bounded Array
  https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
  Difficulty: Medium
  Tags: Binary Search, Greedy
  Time:
  Space:
*/

class Solution {
private:
  static long long sum(long long value, int index, int n) {
    long long sum = 0;
    if (value > index) {
      sum += (value + value - index) * (index + 1) / 2;
    } else {
      sum += (value + 1) * value / 2 + index - value + 1;
    }

    if (value > n - index - 1) {
      sum += (value + value - n + index + 1) * (n - index) / 2;
    } else {
      sum += (value + 1) * value / 2 + n - index - value;
    }

    return sum - value;
  }

public:
  static int maxValue(int n, int index, int maxSum) {
    int left = 1, right = maxSum;
    while (left < right) {
      const auto middle = left + (right - left + 1) / 2;

      if (sum(middle, index, n) > maxSum) {
        right = middle - 1;
      } else {
        left = middle;
      }
    }
    return left;
  }
};
