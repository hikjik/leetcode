#pragma once

#include <queue>
#include <vector>

/*
  2231. Largest Number After Digit Swaps by Parity
  https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
  Difficulty: Easy
  Tags: Sorting, Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
public:
  static int largestInteger(int num) {
    const auto digits = getDigits(num);

    std::vector<std::priority_queue<int>> heaps(2);
    for (auto digit : digits) {
      heaps[digit & 1].push(digit);
    }

    int ans = 0;
    for (auto digit : digits) {
      ans = ans * 10 + heaps[digit & 1].top();
      heaps[digit & 1].pop();
    }
    return ans;
  }

private:
  static std::vector<int> getDigits(int n) {
    std::vector<int> digits;
    for (int i = n; i; i /= 10) {
      digits.push_back(i % 10);
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
  }
};
