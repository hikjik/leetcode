#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

namespace two_pointers {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    int size = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (!i || nums[i] != nums[size - 1]) {
        nums[size++] = nums[i];
      }
    }
    return size;
  }
};

} // namespace two_pointers

namespace stl {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
  }
};

} // namespace stl
