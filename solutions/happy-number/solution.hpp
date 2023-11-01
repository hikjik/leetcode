#pragma once

#include <unordered_set>

/*
  202. Happy Number
  https://leetcode.com/problems/happy-number/
  Difficulty: Easy
  Tags: Hash Table, Math, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static bool isHappy(int n) {
    std::unordered_set<int> seen_before;
    for (int m = n; !seen_before.count(m); m = next(m)) {
      seen_before.insert(m);
    }
    return seen_before.count(1);
  }

private:
  static int next(int n) {
    int m = 0;
    while (n) {
      int r = n % 10;
      m += r * r;
      n /= 10;
    }
    return m;
  }
};