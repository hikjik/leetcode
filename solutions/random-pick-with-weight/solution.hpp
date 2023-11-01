#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  528. Random Pick with Weight
  https://leetcode.com/problems/random-pick-with-weight/
  Difficulty: Medium
  Tags: Array, Math, Binary Search, Prefix Sum, Randomized
  Time:
  Space:
*/

class Solution {
private:
  std::vector<int> ps_;

public:
  Solution(const std::vector<int> &w) : ps_(w.size()) {
    std::partial_sum(w.begin(), w.end(), ps_.begin());
  }

  int pickIndex() {
    const int value = rand() % ps_.back();
    auto ub = std::upper_bound(ps_.begin(), ps_.end(), value);
    return std::distance(ps_.begin(), ub);
  }
};
