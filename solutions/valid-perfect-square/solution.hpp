#pragma once

/*
  367. Valid Perfect Square
  https://leetcode.com/problems/valid-perfect-square/
  Difficulty: Easy
  Tags: Math, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;

    while (left <= right) {
      const long long middle = left + (right - left) / 2;
      const auto square = middle * middle;
      if (square == num) {
        return true;
      } else if (square > num) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return false;
  }
};
