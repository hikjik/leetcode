#pragma once

#include <cstdlib>
#include <vector>

/*
  384. Shuffle an Array
  https://leetcode.com/problems/shuffle-an-array/
  Difficulty: Medium
  Tags: Array, Math, Randomized
  Time:
  Space:
*/

class Solution {
public:
  Solution(std::vector<int> nums) : nums(nums) {}

  std::vector<int> reset() { return nums; }

  std::vector<int> shuffle() {
    std::vector<int> copy(nums);
    int n = copy.size();
    for (int i = 0; i < n - 1; ++i) {
      std::swap(copy[i], copy[i + std::rand() % (n - i)]);
    }
    return copy;
  }

private:
  std::vector<int> nums;
};
