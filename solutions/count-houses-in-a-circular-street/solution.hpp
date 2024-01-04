#pragma once

#include <vector>

// Time: O(K)
// Space: O(1)

class Street {
public:
  explicit Street(std::vector<int> doors) : doors(std::move(doors)) {}

  void openDoor() { doors[i] = 1; }
  void closeDoor() { doors[i] = 0; }
  bool isDoorOpen() const { return doors[i]; }
  void moveRight() { i = (i + 1) % doors.size(); }
  void moveLeft() { i = (i + doors.size() - 1) % doors.size(); }

private:
  int i = 0;
  std::vector<int> doors;
};

class Solution {
public:
  static int houseCount(Street *street, int k) {
    for (int i = 0; i < k; ++i) {
      street->closeDoor();
      street->moveRight();
    }

    street->openDoor();
    int ans = 0;
    do {
      ++ans;
      street->moveRight();
    } while (!street->isDoorOpen());
    return ans;
  }
};
