#pragma once

#include <algorithm>

/*
  2600. K Items With the Maximum Sum
  https://leetcode.com/problems/k-items-with-the-maximum-sum/
  Difficulty: Easy
  Tags: Math, Greedy
  Time:
  Space:
*/

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
