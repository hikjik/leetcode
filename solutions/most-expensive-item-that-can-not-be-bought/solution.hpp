#pragma once

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static int mostExpensiveItem(int primeOne, int primeTwo) {
    return primeOne * primeTwo - primeOne - primeTwo;
  }
};
