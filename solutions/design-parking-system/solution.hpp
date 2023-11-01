#pragma once

#include <array>

/*
  1603. Design Parking System
  https://leetcode.com/problems/design-parking-system/
  Difficulty: Easy
  Tags: Design, Simulation, Counting
  Time:
  Space:
*/

class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small)
      : slots_({big, medium, small}) {}

  bool addCar(int car_type) {
    if (slots_[car_type - 1]) {
      slots_[car_type - 1]--;
      return true;
    }
    return false;
  }

private:
  std::array<int, 3> slots_;
};
