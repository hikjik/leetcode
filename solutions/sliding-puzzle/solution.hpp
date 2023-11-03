#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int slidingPuzzle(const std::vector<std::vector<int>> &board) {
    const std::string target = "123450";
    const std::vector<std::vector<int>> graph{{1, 3}, {0, 2, 4}, {1, 5},
                                              {0, 4}, {1, 3, 5}, {2, 4}};

    std::string source;
    for (const auto &row : board) {
      for (auto num : row) {
        source += std::to_string(num);
      }
    }

    if (source == target) {
      return 0;
    }

    std::queue<std::string> queue{{source}};
    std::unordered_set<std::string> set{source};
    int steps = 0;
    while (!queue.empty()) {
      steps++;
      for (int size = queue.size(); size > 0; --size) {
        auto s = queue.front();
        queue.pop();

        const int i = s.find('0');
        for (int j : graph[i]) {
          std::swap(s[i], s[j]);
          if (s == target) {
            return steps;
          }
          if (!set.count(s)) {
            queue.push(s);
            set.insert(s);
          }
          std::swap(s[i], s[j]);
        }
      }
    }

    return -1;
  }
};
