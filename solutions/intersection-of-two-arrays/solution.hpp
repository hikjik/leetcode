#pragma once

#include <unordered_set>
#include <vector>

/*
  349. Intersection of Two Arrays
  https://leetcode.com/problems/intersection-of-two-arrays/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> intersection(std::vector<int> nums1,
                                       std::vector<int> nums2) {
    std::unordered_set<int> set(nums1.begin(), nums1.end());

    std::vector<int> intersection;
    for (auto a : nums2) {
      if (set.erase(a)) {
        intersection.push_back(a);
      }
    }

    return intersection;
  }
};
