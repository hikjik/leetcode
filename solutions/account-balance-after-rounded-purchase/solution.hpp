#pragma once

/*
  2806. Account Balance After Rounded Purchase
  https://leetcode.com/problems/account-balance-after-rounded-purchase/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int accountBalanceAfterPurchase(int purchaseAmount) {
    return 100 - (purchaseAmount + 5) / 10 * 10;
  }
};
