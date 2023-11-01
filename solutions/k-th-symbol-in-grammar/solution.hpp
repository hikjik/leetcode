#pragma once

/*
  779. K-th Symbol in Grammar
  https://leetcode.com/problems/k-th-symbol-in-grammar/
  Difficulty: Medium
  Tags: Math, Bit Manipulation, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static int kthGrammar(int n, int k) {
    return n == 1 ? 0 : ((k - 1) & 1) ^ kthGrammar(n - 1, ((k - 1) >> 1) + 1);
  }
};
