#pragma once

// Time:
// Space:

class Solution {
public:
  static int accountBalanceAfterPurchase(int purchaseAmount) {
    return 100 - (purchaseAmount + 5) / 10 * 10;
  }
};
