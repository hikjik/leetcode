#pragma once

#include <numeric>
#include <queue>
#include <vector>

// Time: O(NLogN)
// Space: O(N)

class Solution {
private:
  using min_heap = std::priority_queue<int, std::vector<int>, std::greater<>>;

public:
  static std::vector<std::vector<int>>
  highFive(const std::vector<std::vector<int>> &items) {
    std::unordered_map<int, min_heap> studentScores;
    for (const auto &item : items) {
      auto &scores = studentScores[item[0]];
      scores.push(item[1]);
      if (scores.size() > 5) {
        scores.pop();
      }
    }

    std::vector<std::vector<int>> ans;
    for (auto &[id, top5] : studentScores) {
      int sum = 0;
      for (; !top5.empty(); top5.pop()) {
        sum += top5.top();
      }
      ans.push_back({id, sum / 5});
    }
    std::ranges::sort(ans);
    return ans;
  }
};
