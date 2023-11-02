#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int>
  fullBloomFlowers(const std::vector<std::vector<int>> &flowers,
                   const std::vector<int> &people) {
    std::vector<int> starts(flowers.size());
    std::vector<int> ends(flowers.size());
    for (size_t i = 0; i < flowers.size(); ++i) {
      starts[i] = flowers[i][0];
      ends[i] = flowers[i][1];
    }

    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());

    std::vector<int> ans;
    for (auto person : people) {
      auto ub = std::upper_bound(starts.begin(), starts.end(), person);
      auto lb = std::lower_bound(ends.begin(), ends.end(), person);
      ans.push_back(std::distance(starts.begin(), ub) -
                    std::distance(ends.begin(), lb));
    }
    return ans;
  }
};
