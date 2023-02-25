#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int findCircleNum(const std::vector<std::vector<int>> &isConnected) {
    std::vector<bool> visited(isConnected.size(), false);

    int provinces_count = 0;
    for (size_t i = 0; i < isConnected.size(); ++i) {
      if (!visited[i]) {
        provinces_count++;

        std::queue<int> queue;
        queue.push(i);
        visited[i] = true;

        while (!queue.empty()) {
          int i = queue.front();
          queue.pop();

          for (size_t j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] && !visited[j]) {
              queue.push(j);
              visited[j] = true;
            }
          }
        }
      }
    }

    return provinces_count;
  }
};
