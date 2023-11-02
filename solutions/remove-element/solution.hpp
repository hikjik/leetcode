#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace two_pointers {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int removeElement(std::vector<int> &nums, int val) {
    int left = 0, right = nums.size();
    while (left < right) {
      if (nums[left] == val) {
        std::swap(nums[left], nums[--right]);
      } else {
        ++left;
      }
    }
    return right;
  }
};

} // namespace two_pointers

namespace stl {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int removeElement(std::vector<int> &nums, int val) {
    return std::distance(nums.begin(),
                         std::remove(nums.begin(), nums.end(), val));
  }
};

} // namespace stl
