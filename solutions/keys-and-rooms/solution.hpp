#pragma once

#include <queue>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool canVisitAllRooms(const std::vector<std::vector<int>> &rooms) {
    std::unordered_set<int> visited_rooms;

    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
      const auto room = queue.front();
      queue.pop();

      visited_rooms.insert(room);

      for (const auto &adj_room : rooms[room]) {
        if (!visited_rooms.count(adj_room)) {
          queue.push(adj_room);
        }
      }
    }

    return visited_rooms.size() == rooms.size();
  }
};
