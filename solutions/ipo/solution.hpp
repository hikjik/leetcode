#pragma once

#include <algorithm>
#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findMaximizedCapital(int projects_limit, int initial_capital,
                                  const std::vector<int> &profits,
                                  const std::vector<int> &capital) {
    std::vector<std::pair<int, int>> projects;
    projects.reserve(capital.size());
    for (size_t i = 0; i < capital.size(); ++i) {
      projects.emplace_back(capital[i], profits[i]);
    }
    std::sort(projects.begin(), projects.end());

    int current_capital = initial_capital;
    std::priority_queue<int> available_projects;
    for (auto it = projects.begin(); projects_limit; --projects_limit) {
      for (; it != projects.end() && it->first <= current_capital; ++it) {
        available_projects.push(it->second);
      }

      if (available_projects.empty()) {
        break;
      }
      current_capital += available_projects.top();
      available_projects.pop();
    }
    return current_capital;
  }
};
