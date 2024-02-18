#pragma once

#include <queue>
#include <ranges>
#include <vector>

// M = meetings.size()
// Time: O(MlogM+NlogM)
// Space:

class Solution {
private:
  struct Meeting {
    long long endTime;
    int room;
  };

public:
  static int mostBooked(int n, std::vector<std::vector<int>> meetings) {
    std::ranges::sort(meetings);

    std::vector<int> roomsCounter(n);

    const auto greater = [](const Meeting &lhs, const Meeting &rhs) {
      return std::tie(lhs.endTime, lhs.room) > std::tie(rhs.endTime, rhs.room);
    };
    std::priority_queue<Meeting, std::vector<Meeting>, decltype(greater)>
        busyRooms(greater);

    std::priority_queue<int, std::vector<int>, std::greater<>> freeRooms;
    for (int room = 0; room < n; ++room) {
      freeRooms.push(room);
    }

    for (const auto &meeting : meetings) {
      while (!busyRooms.empty() && busyRooms.top().endTime <= meeting[0]) {
        freeRooms.push(busyRooms.top().room);
        busyRooms.pop();
      }

      if (!freeRooms.empty()) {
        const auto room = freeRooms.top();
        freeRooms.pop();
        busyRooms.push({meeting[1], room});
        roomsCounter[room]++;
      } else {
        const auto [end, room] = busyRooms.top();
        busyRooms.pop();
        ++roomsCounter[room];
        busyRooms.push({end + meeting[1] - meeting[0], room});
      }
    }
    return std::ranges::max_element(roomsCounter) - roomsCounter.begin();
  }
};
