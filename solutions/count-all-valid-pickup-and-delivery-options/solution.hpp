#pragma once

/*
  1359. Count All Valid Pickup and Delivery Options
  https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
  Difficulty: Hard
  Tags: Math, Dynamic Programming, Combinatorics
  Time:
  Space:
*/

class Solution {
public:
  static const int kMod = 1e9 + 7;

  static int countOrders(int n) {
    long long cnt = 1;
    for (int i = 1; i <= n; ++i) {
      cnt = cnt * (2 * i - 1) * i % kMod;
    }
    return cnt;
  }
};
