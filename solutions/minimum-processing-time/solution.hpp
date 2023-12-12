#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int minProcessingTime(std::vector<int> processorTime,
                               std::vector<int> tasks) {
    std::ranges::sort(processorTime, std::greater{});
    std::ranges::sort(tasks);

    int ans = 0;
    for (int i = 0; i < std::ssize(processorTime); ++i) {
      ans = std::max(ans, processorTime[i] + tasks[4 * i + 3]);
    }
    return ans;
  }
};
