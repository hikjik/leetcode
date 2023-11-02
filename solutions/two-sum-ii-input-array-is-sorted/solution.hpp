#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        return {left + 1, right + 1};
      }

      if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
    return {};
  }
};
