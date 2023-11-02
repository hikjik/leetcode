#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> asteroidCollision(const std::vector<int> &asteroids) {
    std::vector<int> stack;
    for (auto a : asteroids) {
      if (a > 0) {
        stack.push_back(a);
      } else {
        while (!stack.empty() && stack.back() > 0 && stack.back() < -a) {
          stack.pop_back();
        }
        if (stack.empty() || stack.back() < 0) {
          stack.push_back(a);
        } else if (stack.back() + a == 0) {
          stack.pop_back();
        } else {
        }
      }
    }
    return stack;
  }
};
