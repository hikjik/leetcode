#pragma once

#include <unordered_map>

class Solution {
public:
  static int countLargestGroup(int n) {
    std::unordered_map<int, int> counter;
    int ans = 0;
    for (int i = 1, max = 0; i <= n; ++i) {
      const auto group_size = ++counter[digitsSum(i)];
      if (group_size > max) {
        max = group_size;
        ans = 1;
      } else if (group_size == max) {
        ++ans;
      }
    }
    return ans;
  }

private:
  static int digitsSum(int n) {
    int sum = 0;
    for (auto i = n; i; i /= 10) {
      sum += i % 10;
    }
    return sum;
  }
};
