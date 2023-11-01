#pragma once

#include <numeric>
#include <vector>

/*
  2748. Number of Beautiful Pairs
  https://leetcode.com/problems/number-of-beautiful-pairs/
  Difficulty: Easy
  Tags: Array, Math, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static int countBeautifulPairs(const std::vector<int> &nums) {
    int cnt = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = i + 1; j < nums.size(); ++j) {
        if (std::gcd(firstDigit(nums[i]), lastDigit(nums[j])) == 1) {
          ++cnt;
        }
      }
    }
    return cnt;
  }

private:
  static int firstDigit(int n) {
    while (n > 9) {
      n /= 10;
    }
    return n;
  }
  static int lastDigit(int n) { return n % 10; }
};
