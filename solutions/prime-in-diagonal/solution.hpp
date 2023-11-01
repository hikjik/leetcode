#pragma once

#include <vector>

/*
  2614. Prime In Diagonal
  https://leetcode.com/problems/prime-in-diagonal/
  Difficulty: Easy
  Tags: Array, Math, Matrix, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static int diagonalPrime(const std::vector<std::vector<int>> &nums) {
    const int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (isPrime(nums[i][i])) {
        ans = std::max(ans, nums[i][i]);
      }
      if (isPrime(nums[i][n - i - 1])) {
        ans = std::max(ans, nums[i][n - i - 1]);
      }
    }
    return ans;
  }

private:
  static bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return n != 1;
  }
};
