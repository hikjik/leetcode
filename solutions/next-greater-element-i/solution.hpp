#pragma once

#include <stack>
#include <unordered_map>
#include <vector>

/*
  496. Next Greater Element I
  https://leetcode.com/problems/next-greater-element-i/
  Difficulty: Easy
  Tags: Array, Hash Table, Stack, Monotonic Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> nextGreaterElement(std::vector<int> nums1,
                                             std::vector<int> nums2) {
    std::stack<int> stack;
    std::unordered_map<int, int> umap;
    for (auto num : nums2) {
      while (!stack.empty() && stack.top() < num) {
        umap[stack.top()] = num;
        stack.pop();
      }
      stack.push(num);
    }
    while (!stack.empty()) {
      umap[stack.top()] = -1;
      stack.pop();
    }

    std::vector<int> result;
    result.reserve(nums1.size());
    for (auto num : nums1) {
      result.push_back(umap[num]);
    }
    return result;
  }
};
