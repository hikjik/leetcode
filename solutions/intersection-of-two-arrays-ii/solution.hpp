#pragma once

#include <unordered_map>
#include <vector>

/*
  350. Intersection of Two Arrays II
  https://leetcode.com/problems/intersection-of-two-arrays-ii/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> intersect(const std::vector<int> &nums1,
                                    const std::vector<int> &nums2) {
    std::unordered_map<int, int> counter;
    for (auto num : nums1) {
      counter[num]++;
    }

    std::vector<int> intersection;
    for (auto num : nums2) {
      if (counter[num]) {
        counter[num]--;
        intersection.push_back(num);
      }
    }
    return intersection;
  }
};
