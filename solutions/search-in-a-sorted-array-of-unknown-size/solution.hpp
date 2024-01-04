#pragma once

#include <climits>
#include <vector>

// Time: O(logN)
// Space: O(1)

class ArrayReader {
public:
  explicit ArrayReader(std::vector<int> nums) : nums(std::move(nums)) {}

  int get(int index) const {
    return index < std::ssize(nums) ? nums[index] : INT_MAX;
  }

private:
  std::vector<int> nums;
};

class Solution {
public:
  static int search(const ArrayReader &reader, int target) {
    int l = 0, r = 1;
    while (reader.get(r) < target) {
      l = r + 1;
      r <<= 1;
    }
    while (l < r) {
      const auto m = l + (r - l) / 2;
      reader.get(m) < target ? l = m + 1 : r = m;
    }
    return reader.get(l) == target ? l : -1;
  }
};
