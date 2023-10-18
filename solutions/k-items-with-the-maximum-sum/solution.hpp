#pragma once

#include <algorithm>

class Solution {
public:
  static int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes,
                                  int k) {
    if (numOnes + numZeros >= k) {
      return std::min(numOnes, k);
    }
    return numOnes - std::min(numNegOnes, k - numOnes - numZeros);
  }
};
