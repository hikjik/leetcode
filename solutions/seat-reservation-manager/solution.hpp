#pragma once

#include <queue>
#include <set>

// Time: O(MlogN), where M is the number of calls made
// Space: O(N)

namespace heap {

class SeatManager {
public:
  SeatManager([[maybe_unused]] int n) : marker_(1) {}

  int reserve() {
    if (!available_seats_.empty()) {
      const auto seat_number = available_seats_.top();
      available_seats_.pop();
      return seat_number;
    }
    return marker_++;
  }

  void unreserve(int seat_number) { available_seats_.push(seat_number); }

private:
  std::priority_queue<int, std::vector<int>, std::greater<>> available_seats_;
  int marker_;
};

} // namespace heap

namespace set {

class SeatManager {
public:
  SeatManager([[maybe_unused]] int n) : marker_(1) {}

  int reserve() {
    if (!available_seats_.empty()) {
      const auto seat_number = *available_seats_.begin();
      available_seats_.erase(available_seats_.begin());
      return seat_number;
    }
    return marker_++;
  }

  void unreserve(int seat_number) { available_seats_.insert(seat_number); }

private:
  std::set<int> available_seats_;
  int marker_;
};

} // namespace set
