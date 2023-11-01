#pragma once

#include <queue>
#include <vector>

/*
  1845. Seat Reservation Manager
  https://leetcode.com/problems/seat-reservation-manager/
  Difficulty: Medium
  Tags: Design, Heap (Priority Queue)
  Time:
  Space:
*/

class SeatManager {
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i) {
      queue_.push(i);
    }
  }

  int reserve() {
    const auto seat_number = queue_.top();
    queue_.pop();
    return seat_number;
  }

  void unreserve(int seat_number) { queue_.push(seat_number); }

private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue_;
};
