#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int minMeetingRooms(const std::vector<std::vector<int>> &intervals) {
    std::vector<int> starts, ends;
    for (const auto &interval : intervals) {
      starts.push_back(interval[0]);
      ends.push_back(interval[1]);
    }
    std::ranges::sort(starts);
    std::ranges::sort(ends);

    int ans = 0;
    for (int i = 0, j = 0; i < std::ssize(intervals); ++i) {
      if (starts[i] < ends[j]) {
        ++ans;
      } else {
        ++j;
      }
    }
    return ans;
  }
};
