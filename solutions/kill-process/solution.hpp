#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> killProcess(const std::vector<int> &pid,
                                      const std::vector<int> &ppid, int kill) {
    std::unordered_map<int, std::vector<int>> graph;
    for (int i = 0; i < std::ssize(ppid); ++i) {
      if (ppid[i]) {
        graph[ppid[i]].push_back(pid[i]);
      }
    }

    std::queue<int> queue{{kill}};
    std::vector<int> ans;
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      ans.push_back(u);

      for (auto v : graph[u]) {
        queue.push(v);
      }
    }
    return ans;
  }
};
