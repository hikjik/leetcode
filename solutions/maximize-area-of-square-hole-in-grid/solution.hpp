#pragma once

#include <ranges>
#include <vector>

// Time: O(HlogH+VlogV), H is the size of hBars, V is the size of vBars
// Space: O(H+V)

class Solution {
public:
  static int maximizeSquareHoleArea([[maybe_unused]] int n,
                                    [[maybe_unused]] int m,
                                    const std::vector<int> &hBars,
                                    const std::vector<int> &vBars) {
    const auto size = std::min(maxGap(hBars), maxGap(vBars)) + 1;
    return size * size;
  }

private:
  static int maxGap(std::vector<int> nums) {
    std::ranges::sort(nums);

    int gap = 1, cnt = 1;
    for (int i = 1; i < std::ssize(nums); ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        gap = std::max(gap, ++cnt);
      } else {
        cnt = 1;
      }
    }
    return gap;
  }
};
