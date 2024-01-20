#pragma once

#include <climits>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
private:
  struct Item {
    int num;
    int cnt;
    long long sum;
  };

  static constexpr int kMod = 1e9 + 7;

public:
  static int sumSubarrayMins(const std::vector<int> &nums) {
    std::stack<Item> stack{{{INT_MIN, 0, 0}}};
    long long sum = 0;
    for (auto num : nums) {
      int cnt = 1;
      while (stack.top().num > num) {
        cnt += stack.top().cnt;
        stack.pop();
      }
      stack.push({num, cnt, cnt * num + stack.top().sum});
      sum += stack.top().sum;
    }
    return sum % kMod;
  }
};
