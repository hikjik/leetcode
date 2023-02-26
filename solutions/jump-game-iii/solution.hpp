#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static bool canReach(const std::vector<int> &arr, int start) {
    int n = arr.size();

    std::vector<bool> visited(n, false);
    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
      auto i = queue.front();
      queue.pop();

      if (arr[i] == 0) {
        return true;
      }

      for (auto j : {i + arr[i], i - arr[i]}) {
        if (j >= 0 && j < n && !visited[j]) {
          queue.push(j);
          visited[j] = true;
        }
      }
    }

    return false;
  }
};
