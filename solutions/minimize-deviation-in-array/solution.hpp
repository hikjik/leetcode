#pragma once

#include <set>
#include <vector>

/*
  1675. Minimize Deviation in Array
  https://leetcode.com/problems/minimize-deviation-in-array/
  Difficulty: Hard
  Tags: Array, Greedy, Heap (Priority Queue), Ordered Set
  Time:
  Space:
*/

class Solution {
public:
  static int minimumDeviation(const std::vector<int> &nums) {
    std::set<int> set;
    for (auto num : nums) {
      set.insert(num & 1 ? num * 2 : num);
    }

    auto maximum = *set.rbegin();
    auto deviation = maximum - *set.begin();
    while (maximum % 2 == 0) {
      set.erase(maximum);
      set.insert(maximum / 2);

      maximum = *set.rbegin();
      deviation = std::min(deviation, maximum - *set.begin());
    }
    return deviation;
  }
};
