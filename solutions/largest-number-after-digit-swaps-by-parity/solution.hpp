#pragma once

#include <queue>
#include <vector>

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
